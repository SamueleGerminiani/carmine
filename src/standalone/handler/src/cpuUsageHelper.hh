#pragma once
#include <fstream>
#include <ostream>
#include <string>
#include "globals.hh"
#include <pcre.h>

static unsigned long long lastTotalUser_TOT, lastTotalUser_TOTLow,
    lastTotalSys_TOT, lastTotalIdle_TOT;
static clock_t lastCPU, lastSysCPU, lastUserCPU;
static int numProcessors;
using namespace std;

uint32_t getThiscpuFreq()
{
    uint32_t cpuFreq = 0;

    // CPU frequency is stored in /proc/cpuinfo in lines beginning with "cpu MHz"
    string pattern = "^cpu MHz\\s*:\\s*(\\d+)";
    const char* pcreErrorStr = NULL;
    int pcreErrorOffset = 0;

    pcre* reCompiled = pcre_compile(pattern.c_str(), PCRE_ANCHORED, &pcreErrorStr,
                                    &pcreErrorOffset, NULL);
    if(reCompiled == NULL)
    {
	return 0;
    }

    ifstream ifs("/proc/cpuinfo");
    if(ifs.is_open())
    {
	string line;
	int results[10];

	while(ifs.good())
	{
	    getline(ifs, line);
	    int rc = pcre_exec(reCompiled, 0, line.c_str(), line.length(),
                               0, 0, results, 10);
	    if(rc < 0)
		continue;

	    // Match found - extract frequency
	    const char* matchStr = NULL;
	    pcre_get_substring(line.c_str(), results, rc, 1, &(matchStr));
	    cpuFreq = atol(matchStr);
	    pcre_free_substring(matchStr);
	    break;
	}
    }

    ifs.close();
    pcre_free(reCompiled);

    return cpuFreq;
}

inline void initCPU() {
    FILE *file;
    struct tms timeSample;
    char line[128];

    lastCPU = times(&timeSample);
    lastSysCPU = timeSample.tms_stime;
    lastUserCPU = timeSample.tms_utime;

    file = fopen("/proc/cpuinfo", "r");
    numProcessors = 0;
    while (fgets(line, 128, file) != NULL) {
        if (strncmp(line, "processor", 9) == 0) numProcessors++;
    }
    fclose(file);
}

inline double getCurrentValue() {
    struct tms timeSample;
    clock_t now;
    double percent;

    now = times(&timeSample);
    if (now <= lastCPU || timeSample.tms_stime < lastSysCPU ||
        timeSample.tms_utime < lastUserCPU) {
        // Overflow detection. Just skip this value.
        percent = -1.0;
    } else {
        percent = (timeSample.tms_stime - lastSysCPU) +
                  (timeSample.tms_utime - lastUserCPU);
        percent /= (now - lastCPU);
        percent /= numProcessors;
        percent *= 100;
    }
    lastCPU = now;
    lastSysCPU = timeSample.tms_stime;
    lastUserCPU = timeSample.tms_utime;

    return percent;
}

inline void initCPUTot() {
    FILE *file = fopen("/proc/stat", "r");
    fscanf(file, "cpu %llu %llu %llu %llu", &lastTotalUser_TOT,
           &lastTotalUser_TOTLow, &lastTotalSys_TOT, &lastTotalIdle_TOT);
    fclose(file);
}

inline double getCurrentValueTot() {
    double percent;
    FILE *file;
    unsigned long long totalUser, totalUserLow, totalSys, totalIdle, total;

    file = fopen("/proc/stat", "r");
    fscanf(file, "cpu %llu %llu %llu %llu", &totalUser, &totalUserLow,
           &totalSys, &totalIdle);
    fclose(file);

    if (totalUser < lastTotalUser_TOT || totalUserLow < lastTotalUser_TOTLow ||
        totalSys < lastTotalSys_TOT || totalIdle < lastTotalIdle_TOT) {
        // Overflow detection. Just skip this value.
        percent = -1.0;
    } else {
        total = (totalUser - lastTotalUser_TOT) +
                (totalUserLow - lastTotalUser_TOTLow) +
                (totalSys - lastTotalSys_TOT);
        percent = total;
        total += (totalIdle - lastTotalIdle_TOT);
        percent /= total;
        percent *= 100;
    }

    lastTotalUser_TOT = totalUser;
    lastTotalUser_TOTLow = totalUserLow;
    lastTotalSys_TOT = totalSys;
    lastTotalIdle_TOT = totalIdle;

    return percent;
}

