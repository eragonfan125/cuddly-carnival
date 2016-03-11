.PHONY: all clean install

all: wallworlds

wallworlds: obj/main.o obj/engine.o obj/input.o obj/render.o
	gcc -g -Wall obj/main.o obj/engine.o obj/input.o obj/render.o -o wallworlds -lncurses -lm

obj/main.o:
	mkdir -p obj
	gcc -g -c src/main.c -o obj/main.o

obj/engine.o:
	gcc -g -c src/engine.c -o obj/engine.o

obj/input.o:
	gcc -g -c src/input.c -o obj/input.o

obj/render.o:
	gcc -g -c src/render.c -o obj/render.o

clean:
	rm obj/*.o wallworlds

install:
	echo "Sorry can't do that yet :("
