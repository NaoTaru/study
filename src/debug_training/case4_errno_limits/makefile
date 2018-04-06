.PHONY: all

all:open_limit 

open_limit: open_limit.o
	gcc -o open_limit open_limit.o

open_limit.o: open_limit.c
	gcc -c open_limit.c

.PHONY: clean
clean:
	rm -rf open_limit open_limit.o test*
