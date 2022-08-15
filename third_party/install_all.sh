#!/bin/bash

if [ $# -eq 0 ]
then
    bash install_antlr.sh
    bash install_spotltl.sh
else
    installPrefix="$1"
    bash install_antlr.sh "$installPrefix"
    bash install_spotltl.sh "$installPrefix"
fi


