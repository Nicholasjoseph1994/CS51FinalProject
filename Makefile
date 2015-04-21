#Makefile from cs50
# compiler to use
CC = clang

# flags to pass compiler
CFLAGS = -ggdb3 -O0 -Qunused-arguments -std=c99 -Wall -Werror

# name for executable
EXE = bloom

# space-separated list of header files
HDRS = bloom.h
# HDRS = bloom.h hashtable.h

# space-separated list of source files
SRCS = bloomtest.c bloom.c
# SRCS = bloomtest.c bloom.c hashtable.c

# automatically generated list of object files
OBJS = $(SRCS:.c=.o)


# default target
$(EXE): $(OBJS) $(HDRS) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

# dependencies
$(OBJS): $(HDRS) Makefile

# housekeeping
clean:
	rm -f core $(EXE) *.o

