# -*- Makefile -*-

#target: dependencies
# action

CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=basicMath.o power.o
FLAGS= -Wall -g


all: mymathd mymaths mains maind
mains:  $(OBJECTS_MAIN) mymaths.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) mymaths.a
maind:  $(OBJECTS_MAIN) mymathd.so
	$(CC) $(FLAGS) -o maind $(OBJECTS_MAIN) ./mymathd.so
mymathd: mymathd.so
mymaths: mymaths.a
mymaths.a: $(OBJECTS_LIB)
	$(AR) -rcs mymaths.a $(OBJECTS_LIB)
mymathd.so: $(OBJECTS_LIB)
	$(CC) -shared -o mymathd.so $(OBJECTS_LIB)
basicMath.o: basicMath.c myMath.h
	$(CC) $(FLAGS) -c basicMath.c
power.o: power.c myMath.h
	$(CC) $(FLAGS) -fPIC -c power.c
main.o: main.c myMath.h
	$(CC) $(FLAGS) -c main.c
.PHONY: clean all mymathd mymaths
clean:
	rm -f *.o *.a *.so mains maind
