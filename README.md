# cOMPILER

A tiny-c compiler made using *flex*, *yacc*, and *gnu assembler*.
tiny-c has instructions are a subset of instructions from C.
Targetted for x86_64 architecture.

Written for Compilers Course (CS39003). To know more about tiny-c, go through the [docs](docs/) folder.

## Testing

The test files can be found in the `tests` folder. Run them with - `make testi` , i = 1 to 5

Test your own tiny-c file with :
<pre style="background: rgb(238, 238, 238); border: 1px solid rgb(204, 204, 204); padding: 5px 10px;">make
./a.out < testfile.c  test_s_file_name
gcc -c test_s_file_name.s -o test_o_file_name.o
gcc test_o_file_name.o -L. -g -lmylib -o test.out
.test.out</pre>
P.S : The compiler assumes your tiny c file is correct, so if a segmentation fault is faced, make sure your test file is tiny-c compatible.

The quads generated for this program can be found in the test folder.
