# -*- Makefile -*-

#target: dependencies
# action

CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=basicMath.o power.o
FLAGS= -Wall -g

all: libmyMath.so libmyMath.a mymaths mymathd

mains: libmyMath.a mymaths
	$(CC) $(FLAGS) -o mains main.o libmyMath.a
maind: libmyMath.so mymathd
	$(CC) $(FLAGS) -o maind main.o ./libmyMath.so

mymaths: $(OBJECTS_MAIN) libmyMath.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libmyMath.a
mymathd: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o maind $(OBJECTS_MAIN) ./libmyMath.so
libmyMath.so: $(OBJECTS_LIB)
	$(CC) -shared -o libmyMath.so $(OBJECTS_LIB)
libmyMath.a: $(OBJECTS_LIB)
	$(AR) -rcs libmyMath.a $(OBJECTS_LIB)
basicMath.o: basicMath.c myMath.h
	$(CC) $(FLAGS) -c basicMath.c
power.o: power.c myMath.h
	$(CC) $(FLAGS) -c power.c
main.o: main.c myMath.h
	$(CC) $(FLAGS) -c main.c
.PHONY: clean all
clean:
	rm -f *.o *.a *.so mains maind
