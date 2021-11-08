#pragma once
#include <fstream>
#include <ostream>
#include <string>
#include "globals.hh"

static unsigned long long lastTotalUser_TOT, lastTotalUser_TOTLow,
    lastTotalSys_TOT, lastTotalIdle_TOT;
static clock_t lastCPU, lastSysCPU, lastUserCPU;
static int numProcessors;

inline void initMaxFreq() {
    if (machineCPUfreq == 0) {
        std::ifstream myfile(
            "/sys/devices/system/cpu/cpu0/cpufreq/scaling_min_freq");
        std::string text = "";
        if (getline(myfile, text)) machineCPUfreq= std::stoul(text);
        myfile.close();
    }
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

