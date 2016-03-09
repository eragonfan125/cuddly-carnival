all: wallworlds

wallworlds: obj/main.o obj/engine.o obj/input.o obj/render.o
	gcc -Wall main.c engine.c input.c render.c -o wallworlds -lncurses -lm

obj/main.o:
	gcc -c -o obj/main.o

obj/engine.o:
	gcc -c -o obj/engine.o

obj/input.o:
	gcc -c -o obj/input.o

obj/render.o:
	gcc -c -o obj/render.o

clean:
	rm obj/*.o wallworlds
