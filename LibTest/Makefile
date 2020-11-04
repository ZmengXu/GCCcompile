CC=gcc
AR=ar
CFLAGS=-Wall -g
#(r) replace (c) create (s) index
ARFLAGS=rcs
BINS=libStaticTest.a libDynamicTest.so mainStaticExe mainDynamicExe

all: $(BINS)

test.o: test.c
	$(CC) $(CFLAGS) -c test.c

#
libStaticTest.a: test.o
	$(AR) $(ARFLAGS) $@ $^

mainStaticExe: main.c
	$(CC) $(CFLAGS) -o $@ $^ -L. -lStaticTest

libDynamicTest.so: test.c
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^

mainDynamicExe: main.c
	$(CC) $(CFLAGS) -o $@ $^ -L. -lDynamicTest

clean:
	rm -rf $(BINS)
	rm -rf *.so *.o *Exe

run:
	./mainStaticExe
	LD_LIBRARY_PATH="$PWD;$LD_LIBRARY_PATH"
	./mainStaticExe