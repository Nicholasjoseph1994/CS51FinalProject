#Makefile from cs50
# compiler to use
CC = clang

# flags to pass compiler
CFLAGS = -g -ggdb3 -O0 -Qunused-arguments -std=c99 -Wall -Werror

# name for executable
EXE = hashtable

# space-separated list of header files
HDRS = hashtable.h
# HDRS = bloom.h hashtable.h

# space-separated list of source files
SRCS = hashtable.c
# SRCS = bloomtest.c bloom.c hashtable.c

# automatically generated list of object files
OBJS = $(SRCS:.c=.o)


# default target
all: hashtable bloom trie autocorrect

hashtable: hashtable.o hashtable.h Makefile
	$(CC) $(CFLAGS) -o $@ hashtable.o 

bloom: bloom.o bloomtest.o bloom.h Makefile
	$(CC) $(CFLAGS) -o $@ bloom.o  bloomtest.o

trie: trie.o trie.h Makefile
	$(CC) $(CFLAGS) -o $@ trie.o 

autocorrect: autocorrectTrain.o autocorrectTrainTest.o autocorrectTrain.h Makefile
	$(CC) $(CFLAGS) -o $@ autocorrectTrain.o  autocorrectTrainTest.o

# dependencies
#$(OBJS): $(HDRS) Makefile

# housekeeping
clean:
	rm -f core $(EXE) *.o

