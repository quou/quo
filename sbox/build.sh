#!/bin/bash

if [ ! -d "bin" ]; then
	mkdir "bin"
fi

gcc src/sbox.c -I ../quo -lX11 -lGL -lm -o bin/sbox
