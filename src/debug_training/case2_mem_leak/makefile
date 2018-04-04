.PHONY: all

all:malloc_loop 

malloc_loop: malloc_loop.o
	gcc -o malloc_loop malloc_loop.o

malloc_loop.o: malloc_loop.c
	gcc -c malloc_loop.c

.PHONY: clean
clean:
	rm -rf malloc_loop malloc_loop.o
