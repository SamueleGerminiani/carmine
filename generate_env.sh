if [ "$#" -ne 1 ]; then
    echo "Missing argument: call as ./generate_env.sh <specification.xml>"
	exit
fi


#Clean verification_env directory
rm -rf ./verification_env
mkdir ./verification_env

#Generate environment
./build/carmine $1

if [ "$?" -eq 1 ]; then
    echo "Could not generate verification environment"
	exit
fi

#Move generated files
cp -rf ./src/standalone/scheduler ./verification_env/
cp -rf ./src/standalone/srv ./verification_env/
cp ./src/standalone/CMakeLists.txt ./verification_env/
cp ./src/standalone/package.xml ./verification_env/

cp -R ./build/output/checkers/ ./verification_env/
cp ./src/standalone/checkers/Checker.hpp ./verification_env/checkers/include
cp -R ./build/output/ver_env/ ./verification_env/

cp ./src/standalone/launchN.sh ./verification_env/
#cp ./src/standalone/killAll.sh ./verification_env/

echo "Successfully generated verification environment: output in verification_env directory"
