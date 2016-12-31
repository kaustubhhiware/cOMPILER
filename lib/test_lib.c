#include "stdio.h"
#include "myl.h"
#define ERR 1
#define OK 0
#include "mylib.c"
int main()
{
/*
	The purpose of this file is to check the functions in mylib.c
*/

	printf("\n+--- Testing prints \n");
	//test prints
	int sizestr;
	char str[100];
	printf("Enter a string : ");
	scanf("%s",str);
	sizestr = prints(str);
	printf("\nThe size of %s is %d\n",str,sizestr);


	printf("\n+--- Testing printi \n");
	//test printi
	int size1,size2;
	int num1,num2;
	printf("Enter a positive number : ");
	scanf("%d",&num1);
	size1 = printi(num1);
	printf("\nThe size of %d is %d\n",num1,size1);
	printf("Enter a negative number : ");
	scanf("%d",&num2);
	size2 = printi(num2);
	printf("\nThe size of %d is %d\n",num2,size2);

	printf("\n+--- Testing printd \n");
	//test printd
	int sizef;
	float f;
	printf("Enter a float : ");
	scanf("%f",&f);
	sizef = printd(f);
	printf("\nThe size of %f is %d\n",f,sizef);

	//test readi
	printf("\n+--- Testing readi \nEnter an integer : \n");
	int n = 0;
	int eP = readi(&n);
	
	if(!eP)
	{
		printf("The input was valid = %d\n",n );
	}
	else
	{
		printf("Error in formatting ! Bad input\n");
	}

	//test readf
	printf("\n+--- Testing readf \nEnter a float :\n");
	int err = 0;
	float fP = 0 ;
	err = readf(&fP) ;

	if(err==OK)
	{
		printf("The input was valid = %f\n",fP );
	}
	else
	{
		printf("Error in formatting ! Bad input\n");
	}


}