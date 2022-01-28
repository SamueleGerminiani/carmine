#!/bin/sh

if [ "$1" -ne 1 ]; then
    echo "Missing argument: call as ./generate_env.sh <specification.xml>"
	exit
fi


#Clean ver_env directory
rm -rf ./ver_env
mkdir ./ver_env/
mkdir ./ver_env/handler/
mkdir ./ver_env/handler/src

#Generate environment
#gdb -ex run -ex backtrace --args ./build/carmine $1
./build/carmine $1

if [ "$?" -eq 1 ]; then
    echo "Could not generate verification environment"
	exit
fi

#Move generated files
cp -r ./src/standalone/scheduler ./ver_env/
cp ./src/standalone/handler/src/* ./ver_env/handler/src/
cp -r ./src/standalone/commandLineParser ./ver_env/
cp -r ./src/standalone/msg ./ver_env/
cp -r ./src/standalone/action ./ver_env/

#find type of isa
archType=$(uname -m)
if [ "$archType" = "x86_64" ]; then
    cp -r ./src/standalone/lib ./ver_env/
else
    cp -r ./src/standalone/libarm ./ver_env/lib
fi
cp -r ./src/standalone/cmake ./ver_env/

#add msg_gen and cpu_oh as dependencies
if [ "$2" = "--debug" ]; then
    cp ./src/standalone/CMakeListsDebug.txt ./ver_env/CMakeLists.txt
    cp ./src/standalone/packageDebug.xml ./ver_env/package.xml
else
    cp ./src/standalone/CMakeLists.txt ./ver_env/
    cp ./src/standalone/package.xml ./ver_env/
fi

cp -r ./build/output/checkers ./ver_env/
cp -r ./build/output/ver_env/src/* ./ver_env/handler/src/
cp ./src/standalone/checkers/Checker.hpp ./ver_env/checkers/include/

cp ./src/standalone/debugLaunchN.sh ./ver_env/
cp ./src/testbench/loadTB.sh ./ver_env/

echo "Successfully generated verification environment: output in ver_env directory"
