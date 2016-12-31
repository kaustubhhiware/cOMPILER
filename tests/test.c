int main()
{
	int a[10];
	int i,j,temp;
	for(i=0;i<10;i++)
	{
		a[i] = 10 - i;
	}
	prints("Array Before Sorting\n");
	for(i=0;i<10;i++)
	{
		printi(a[i]);
		prints("\n");
	}
	for(i=0;i<9;i++)
	{
		for(j=0;j<9-i;j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	prints("Array After Sorting\n");
	for(i=0;i<10;i++)
	{
		printi(a[i]);
		prints("\n");
	}
	return 0;
}