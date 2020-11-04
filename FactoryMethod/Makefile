test:test.c
	g++ -o test test.c
all:main.o 
	g++ -o main main.o 
main.o:main.c
	g++ -c main.c
.PHONY:clean
clean:
	rm -f test main main.o 
