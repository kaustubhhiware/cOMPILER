a.out: lex.yy.c y.tab.c y.tab.h compiler_translator.h compiler_translator.cxx compiler_target_translator.cxx libmylib.a
	g++ -std=c++11 lex.yy.c y.tab.c compiler_translator.cxx compiler_target_translator.cxx -lfl -o a.out

# PLEASE DO NOT REMOVE libmylib
# ALSO in lib/LIB/
# PROGRAM SAYS THIS OTHERWISE
# /usr/bin/ld: skipping incompatible ./libmylib.a when searching for -lmylib
# /usr/bin/ld: cannot find -lmylib
# collect2: error: ld returned 1 exit status
libmylib.a: mylib.o
	ar -rcs libmylib.a mylib.o

mylib.o: mylib.c myl.h
	gcc -Wall -c mylib.c

y.tab.h: compiler_actions.y
	yacc -dtv compiler_actions.y 
y.tab.c: compiler_actions.y
	yacc -dtv compiler_actions.y 
lex.yy.c: compiler_lexer.l y.tab.h
	flex compiler_lexer.l

clean: 
	rm a.out y.tab.h y.tab.c lex.yy.c y.output

test1: a.out tests/test1.c
	./a.out < tests/test1.c  test1
	gcc -c tests/test1.s -o tests/test1.o
	gcc tests/test1.o -L. -g -lmylib -o tests/test1.out
	./tests/test1.out

test2: a.out tests/test2.c
	./a.out < tests/test2.c  test2
	gcc -c tests/test2.s -o tests/test2.o
	gcc tests/test2.o -L. -g -lmylib -o tests/test2.out
	./tests/test2.out

test3: a.out tests/test3.c
	./a.out < tests/test3.c  test3
	gcc -c tests/test3.s -o tests/test3.o
	gcc tests/test3.o -L. -g -lmylib -o tests/test3.out
	./tests/test3.out

test4: a.out tests/test4.c
	./a.out < tests/test4.c  test4
	gcc -c tests/test4.s -o tests/test4.o
	gcc tests/test4.o -L. -g -lmylib -o tests/test4.out
	./tests/test4.out

test5: a.out tests/test5.c
	./a.out < tests/test5.c  test5
	gcc -c tests/test5.s -o tests/test5.o
	gcc tests/test5.o -L. -g -lmylib -o tests/test5.out
	./tests/test5.out
