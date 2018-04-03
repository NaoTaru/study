.PHONY: all
all: hello

hello: hello.o
	gcc -o hello hello.o

hello.o: hello.c
	gcc -c hello.c

hello.o: hello.h

.PHONY: clean
clean:
	rm -rf hello hello.o