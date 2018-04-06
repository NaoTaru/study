.PHONY: all

all:open_loop 

open_loop: open_loop.o
	gcc -o open_loop open_loop.o

open_loop.o: open_loop.c
	gcc -c open_loop.c

.PHONY: clean
clean:
	rm -rf open_loop open_loop.o test*
