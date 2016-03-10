.PHONY: all clean

all: wallworlds

wallworlds: obj/main.o obj/engine.o obj/input.o obj/render.o
	gcc -Wall obj/main.o obj/engine.o obj/input.o obj/render.o -o wallworlds -lncurses -lm

obj/main.o:
	mkdir -p obj
	gcc -c src/main.c -o obj/main.o

obj/engine.o:
	gcc -c src/engine.c -o obj/engine.o

obj/input.o:
	gcc -c src/input.c -o obj/input.o

obj/render.o:
	gcc -c src/render.c -o obj/render.o

clean:
	rm obj/*.o wallworlds
