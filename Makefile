all:
	gcc main.c engine.c input.c render.c -o WallWorlds -lncurses -lm