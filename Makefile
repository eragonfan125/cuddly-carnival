.PHONY: all clean

all: wallworlds

wallworlds: obj/main.o obj/engine.o obj/input.o obj/render.o
	gcc -Wall main.c engine.c input.c render.c -o wallworlds -lncurses -lm

obj/main.o:
	mkdir -p obj
	gcc -c main.c -o obj/main.o

obj/engine.o:
	gcc -c engine.c -o obj/engine.o

obj/input.o:
	gcc -c input.c -o obj/input.o

obj/render.o:
	gcc -c render.c -o obj/render.o

clean:
	rm obj/*.o wallworlds
