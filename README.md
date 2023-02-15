the so_long project, using the codam MLX42

you need homebrew/42homebrew and glfw for this project.
if you don't have them:
before compiling, do "make brew" to install 42 homebrew, followed by "make glfw" to install it.
if you have homebrew and not glfw, simply "make glfw" will work.
you can then "make" to compile everything.
you need to launch the program with an argument (the map). maps are provided in the maps folder. you can add your own or simply give the right path to it.

example: ./so_long maps/map1.ber

the map has to be a .ber file, it will not work with any other extension as per the requirements of the project. if you need it to work with any type of file, the condition for it is in the map_reader.c file. simply change the return value of the ber_check function to 1, the rest will work as intended.
