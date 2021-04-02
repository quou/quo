#! /bin/bash

if [ ! -d "bin" ]; then
	mkdir "bin"
fi

echo "compiling examples..."

gcc cube.c -I../quo -lGL -lX11 -lm -o "bin/cube"
gcc input.c -I../quo -lGL -lX11 -lm -o "bin/input"
gcc offscreen_rendering.c -I../quo -lGL -lX11 -lm -o "bin/offscreen_rendering"
gcc serialisation.c -I../quo -lGL -lX11 -lm -o "bin/serialisation"
gcc texture.c -I../quo -lGL -lX11 -lm -o "bin/texture"
gcc window_renderer.c -I../quo -lGL -lX11 -lm -o "bin/window_renderer"

echo "done."
