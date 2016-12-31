int printi(int num);
int prints(char * c);
int readi(int *eP);

int factorial(int n)
{
  if (n == 0)
    return 1;
  else{
	int x;
	x = factorial(n-1);
  }
    return(n * x);
}

int main()
{
	int num, fact;
	prints("\nWhat numbers factorial is to be found ? ");
	int p;
	num = readi(&p);
	if(num>20)
	{
		prints("\nThis might take time.Try a smaller number\n");
	}
	else
	{
		fact = factorial(num);
		printi(num);
		prints("! = ");
		printi(fact);
		prints("\n");
	}

	
	return 0;
}
