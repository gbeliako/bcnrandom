CC=gcc

IDIR = ./code
SDIR = ./code
ODIR = ./obj
BDIR = ./bin

CFLAGS=-I$(IDIR) -O3 -g -msse2 

DEPS = $(SDIR)/bcnrandomc.h
OBJ = $(ODIR)/testbcnrand.o


all: testbcnrand


testbcnrand: $(OBJ)
	$(CC) $(CFLAGS) -o $(BDIR)/testbcnrand $(ODIR)/testbcnrand.o


$(ODIR)/testbcnrand.o: 	$(SDIR)/testbcnrand.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
