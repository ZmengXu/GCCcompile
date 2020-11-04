CC=gcc
CFLAGS=-Wall -g
LDLIBS=-ldl
BINS=libplus1.so libplus2.so test.o

all: $(BINS)

%.so: %.c
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

clean:
	rm -f $(BINS)
	rm -f *.so *.o

run:
	LD_LIBRARY_PATH="$PWD;$LD_LIBRARY_PATH"
	./test.o "libplus1.so" 1
	./test.o "libplus2.so" 1
