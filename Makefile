all: wallworlds

wallworlds: obj/main.o obj/engine.o obj/input.o obj/render.o
	gcc -Wall main.c engine.c input.c render.c -o wallworlds -lncurses -lm

obj/main.o:
	if [ ! -d obj ]; then mkdir obj; fi
	gcc -c -o main.c obj/main.o

obj/engine.o:
	gcc -c -o engine.c obj/engine.o

obj/input.o:
	gcc -c -o input.c obj/input.o

obj/render.o:
	gcc -c -o render.c obj/render.o

clean:
	rm obj/*.o wallworlds
