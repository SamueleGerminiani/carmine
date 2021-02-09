if [ "$#" -ne 1 ]; then
    echo "Missing argument: call as ./generate_env.sh <specification.xml>"
	exit
fi

#Clean output directories
rm ./output/checkers/src/*.cpp 2> /dev/null
rm ./output/ver_env/src/ver_env.cpp 2> /dev/null
#Delete everything except Checker.hpp
rm ./output/checkers/include/*.hh 2> /dev/null

#Clean verification_env directory
rm -rf ./verification_env/checkers/ 2> /dev/null
rm -rf ./verification_env/ver_env/ 2> /dev/null

#Generate environment
./build/carmine $1

if [ "$?" -eq 1 ]; then
    echo "Could not generate verification environment"
	exit
fi

#Move generated files
cp -R ./output/checkers/ ./verification_env/
cp -R ./output/ver_env/ ./verification_env/

echo "Successfully generated verification environment: output in verification_env directory"
