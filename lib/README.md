# README for library
This folder contains the library to implement printf, cin type of functions.

The functions required for tiny-c are :
* `int prints(char *)` - prints a string of characters. The parameter
 is terminated by ‘\0’. The return value is the number of characters
 printed.

*  `int printi(int n)` - prints the integer value of n (no newline).  It returns the number of characters printed.

* `int readi(int *eP)` - reads an integer (signed) and returns it. The
 parameter is for error (ERR = 1, OK = 0).

* `int readf(float *fP)` - reads a floating point number in ’%f’ for-
 mat e.g. -123.456. Caller get the value through the pointer param-
 eter. The return value is ERR or OK.

* `int printd(float f)` - prints the floating point number passed as
parameter. Returns the number of characters printed.


A basic test file `test_lib.c` is provided to check all functions.

Run it with

<pre style="background: rgb(238, 238, 238); border: 1px solid rgb(204, 204, 204); padding: 5px 10px;">make
./a.out </pre>
