int printi(int num);
int prints(char * c);
int readi(int *eP);

int main()
{
	int a[10];
	int b[10];
	int p, n, x, i, y, z;
	prints("\nEnter size of 2 arrays a and b: ");	
	n = readi(&p);
	prints("Enter contents of a:\n");
	for(i = 0; i < n; i++ )
	{
		x = readi(&p);
		a[i] = x;
	}
	//prints("\n");
	prints("Enter contents of b:\n");
	for(i = 0; i < n; i++ )
	{
		x = readi(&p);
		b[i] = x;
	}
	prints("The elements of the modulo array are:\n");
	for( i = 0; i < n; i++ )
	{
		x = a[i];	
		y = b[i];
		z = x % y;
		printi(z);
		prints(" ");
	}
	prints("\n");
	return 0;
}
