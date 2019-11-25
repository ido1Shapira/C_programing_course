# -*- Makefile -*-

CC=gcc
CFLAGS=-I.
FLAGS = -Wall -g
DEPS = myBank.h
OBJECTS_MAIN = main.o

# $@ - the file on the left side of the :
# $< - the first name in the dependencies list
# $^ - the right side of :

#$(TARGET): $(OBJ) lib.a
#	$(CC) -o $@ $^ $(CFLAGS)
mains:  $(OBJECTS_MAIN) myBank.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) myBank.a

myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -fPIC -c myBank.c

#%.o: %.c $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)

# by convention, it starts with lib and ends with .a
myBank.a: myBank.o   # can also add here more objects
	ar rcs $@ $^

.PHONY: clean

clean:
	rm -f *.o *.a mains
