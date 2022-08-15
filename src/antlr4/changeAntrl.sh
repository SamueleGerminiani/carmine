#!/bin/sh

cd PSLParser/grammar/
java -jar "$1" -Dlanguage=Cpp -lib ../../propositionParser/grammar/ temporal.g4
mv *.h include
mv *.cpp src
cd ../../

cd propositionParser/grammar/
java -jar "$1" -Dlanguage=Cpp proposition.g4
mv *.h include
mv *.cpp src
cd ../../

cd varDeclarationParser/grammar/ 
java -jar "$1" -Dlanguage=Cpp varDeclaration.g4
mv *.h include
mv *.cpp src
cd ../../
