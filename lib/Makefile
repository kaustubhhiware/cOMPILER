a.out: test_lib.o mylib.a
	cc test_lib.o -L. -lmylib

test_lib.o: test_lib.c myl.h
	cc -Wall -c test_lib.c

mylib.a: mylib.o
	ar -rcs mylib.a mylib.o

mylib.o: mylib.c myl.h
	cc -Wall -c mylib.c

clean:
	rm a.out test_lib.o mylib.a mylib.o