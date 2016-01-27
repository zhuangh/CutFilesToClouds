
CC = cc
LINT = lint

CFLAGS = -O

splits: splits.o
	$(CC) $(CFLAGS) splits.o -o splits
	strip splits
	
splits_func: splits_func.o
	$(CC) $(CFLAGS) splits_func.o -o splits_func
	strip splits_func
	

clean:
	rm -f splits *.bak core *.out *.o *.zip

RELFILES = Makefile splits.1 splits.c splits.exe \
	   splits.html splits.gif splits.man test.bat

release:
	rm -f splits.zip
	zip  splits.zip $(RELFILES)

lint:
	$(LINT) -h splits.c

manpage:
	nroff -man splits.1 | more

printman:
	ptroff -man splits.1

#   The following test should produce no error messages from splits or CMP

test:	splits
	cat splits splits.c splits splits.c splits splits >test.bak
	cat test.bak test.bak test.bak test.bak >test1.bak
	cat test1.bak test1.bak test1.bak test1.bak test1.bak >test.bak
	rm test1.bak
	splits test.bak
	cat test.bak.0* | cmp - test.bak
	rm test.bak.0*
	cat test.bak | splits - 64
	cat StdIn.0* | cmp - test.bak
	rm StdIn.0*
	rm test.bak
