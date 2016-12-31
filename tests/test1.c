int printi(int n);
int readi(int *eP);
int prints(char *str);

int fibonaci(int i) 
{

   if(i < 2) return i;
   int a,b,c;
   a = fibonaci(i-1);
   b = fibonaci(i-2);
   c = a + b;
   return c;
}
int main()
{
	int num,fib;
	prints("\nWhat number's fibonacci term is to be found ?\n");
	int p;
	num = readi(&p);
	if(num>20)
	{
		prints("\nThis might take time.Try a smaller number\n");
	}
	else
	{
		fib = fibonaci(num);
		prints("\nThe ");
		printi(num);
		prints("th fibonacci is : ");
		printi(fib);
		prints("\n");
	}
	return 0;
}
