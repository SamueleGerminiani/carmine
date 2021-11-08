if [ "$#" -ne 1 ]; then
    echo "Missing argument: call as ./generate_env.sh <specification.xml>"
	exit
fi


#Clean verification_env directory
rm -rf ./verification_env
mkdir ./verification_env/
mkdir ./verification_env/ver_env/
mkdir ./verification_env/ver_env/src

#Generate environment
#gdb -ex run -ex backtrace --args ./build/carmine $1
./build/carmine $1

if [ "$?" -eq 1 ]; then
    echo "Could not generate verification environment"
	exit
fi

#Move generated files
cp -r ./src/standalone/scheduler ./verification_env/
cp ./src/standalone/ver_env/src/* ./verification_env/ver_env/src/
cp -r ./src/standalone/commandLineParser ./verification_env/
cp -r ./src/standalone/msg ./verification_env/
cp -r ./src/standalone/action ./verification_env/
cp -r ./src/standalone/lib ./verification_env/
cp -r ./src/standalone/cmake ./verification_env/
cp ./src/standalone/CMakeLists.txt ./verification_env/
cp ./src/standalone/package.xml ./verification_env/

cp -r ./build/output/checkers ./verification_env/
cp -r ./build/output/ver_env/src/* ./verification_env/ver_env/src/
cp ./src/standalone/checkers/Checker.hpp ./verification_env/checkers/include/

cp ./src/standalone/debugLaunchN.sh ./verification_env/
#cp ./src/standalone/killAll.sh ./verification_env/

echo "Successfully generated verification environment: output in verification_env directory"
