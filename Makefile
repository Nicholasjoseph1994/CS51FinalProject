#Makefile from cs50
# compiler to use
CC = clang

# flags to pass compiler
CFLAGS = -g -ggdb3 -O0 -Qunused-arguments -std=c99 -Wall -Werror

all: hashtable bloom trie autocorrect test

hashtable: hashtable.o hashtableTest.o hashtable.h Makefile
	$(CC) $(CFLAGS) -o $@ hashtable.o hashtableTest.o

bloom: bloom.o bloomtest.o bloom.h Makefile
	$(CC) $(CFLAGS) -o $@ bloom.o bloomtest.o

trie: trie.o trie.h Makefile
	$(CC) $(CFLAGS) -o $@ trie.o

autocorrect: hashtable.o autocorrectTrain.o autocorrectTrainTest.o autocorrectTrain.h Makefile
	$(CC) $(CFLAGS) -o $@ hashtable.o autocorrectTrain.o autocorrectTrainTest.o

test: hashtable.o autocorrectTrain.o readinfile.o autocorrectTrain.h Makefile
	$(CC) $(CFLAGS) -o $@ hashtable.o autocorrectTrain.o readinfile.o
# dependencies

# housekeeping
clean:
	rm -f core $(EXE) *.o

