#
#         Name: Michael Marven
#      Purpose: Linux Makefile for RangeCheck template class and test program
#
#

CC=g++
DEBUG=-g
CFLAGS=$(DEBUG)
PROGS=rctest

all: $(PROGS)

rctest : rctest.o rangecheck.o
	$(CC) -g rangecheck.o rctest.o -o rctest
    
rangecheck.o : rangecheck.cpp rangecheck.h
	$(CC) -g -c -std=c++0x rangecheck.cpp

rctest.o : rctest.cpp rangecheck.h
	$(CC) -g -c -std=c++0x rctest.cpp
    
clean:
	rm -rf *.o $(PROGS)