.PHONY: all
all: hello

hello: hello.o hi.o
	gcc -o hello hello.o hi.o

hi.o: hi.c
	gcc -c hi.c

hello.o: hello.c
	gcc -c hello.c

.PHONY: clean
clean:
	rm -rf hello hello.o hi.o