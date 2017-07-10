#!/bin/sh

cmake --version;

if [[ $? == 127 ]]; then
	echo "Please, install cmake" ;
	exit ;
fi

git clone https://github.com/SFML/SFML.git
(cd SFML && cmake . && make);