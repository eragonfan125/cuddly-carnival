all:
	gcc -Wall main.c engine.c input.c render.c -o ww.out -lncurses -lm
