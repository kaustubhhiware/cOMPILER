int printi(int num);
int prints(char * c);
int readi(int *eP);

int gcd(int m, int n)
{
    if (n) {
		int a, b;
		a = m % n;
		b = gcd(n, a);
	        return b;
    }
    else 
       return m;
}

int main()
{
	int a, b, c, p;
	prints("\nEnter a positive number(a) :");
	a = readi(&p);
	prints("\nEnter a positive number(b) :");
	b = readi(&p);	
	prints("The gcd of ");
	printi(a);
	prints(" & ");
	printi(b);
	prints(" is : ");
	c = gcd(a, b);
	printi(c);
	prints("\n");	
	return 0;
}
