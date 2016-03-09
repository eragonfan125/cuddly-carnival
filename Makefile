all: wallworlds

wallworlds: obj/main.o obj/engine.o obj/input.o obj/render.o
	gcc -Wall main.c engine.c input.c render.c -o wallworlds -lncurses -lm

obj/main.o: src/main.c
	gcc -c -o obj/main.o

obj/engine.o: src/engine.c
	gcc -c -o obj/engine.o

obj/input.o: src/input.c
	gcc -c -o obj/input.o

obj/render.o: src/render.c
	gcc -c -o obj/render.o

clean:
	rm obj/*.o wallworlds
