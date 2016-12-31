#include "myl.h"
//#include <asm/unistd.h>
//#include <syscall.h>
//#include "stdio.h"
#define BUFF 100
char buff[BUFF];

// some mistakes were made in the original file , so those are rectified like 
// not reporting ERR for incorrect files
// and bytes = len(=i)+1 was returned instead of i

/* Prints the string ..returns number of chars printed */
int prints(char* str)
{
	if(str == 0)
		return ERR;										
	int i=0;
	while(str[i]!='\0')	{
		i++;
	}
	
	__asm__ __volatile__ (
						"movl $4, %%eax \n\t"
						"movl $1, %%ebx \n\t"
						"int $128 \n\t"
						:
						://Inputs
						"c"(str),
						"d"(i)
						) ; 
	return i;											
}

/* Prints integer value of n ..returns number of chars printed */
int printi(int n)
{
	int i=0,j=0,bytes;
	char temp,zero='0';											
	if(n==0){
		buff[i++] = zero;								
		bytes = i;
	}
	else
	{
		if(n < 0)
		{
			buff[i++] = '-';							
			n = -n;
			j=i;
		}
		while(n)
		{
			int dig = n % 10;
            buff[i++] = (char) (zero + dig);
            n /= 10;									//divide the number by 10
		}
		bytes = i--;
		while(j<i)										
		{
			temp    = buff[i];
			buff[i--] = buff[j];
			buff[j++] = temp;
		}
	}

	__asm__ __volatile__ (
						"movl $4, %%eax \n\t"
						"movl $1, %%ebx \n\t"
						"int $128 \n\t"
						:
						:"c"(buff), "d"(bytes)
	) ; 
	return bytes;
}

/*reads a signed integer and returns pointer ... return status */
int readi(int *n)
{
	int i=0,j=0,isneg=0;
	*n = 0;
	do
	{
		i=j=0;
		__asm__ __volatile__ (
							"movl $3, %%eax \n\t"
							"movl $0, %%ebx \n\t"
							"int $128 \n\t"
							:
							:"c"(buff)
							) ; 

		while(buff[i] == ' ' || buff[i] == '\t')
		{
			i++;j++;
		}
	}while(buff[i]=='\n');	

	while(buff[i]!='\n' && buff[i]!=' ' && buff[i]!='\t')
	{
		if(i==j && buff[i]=='-')
		{
			if(isneg){
				*n=0;
				return ERR;
			}
			else {
				i++;j++;
				isneg=1;
				continue;
			}
		}

		if(buff[i] < '0' || buff[i] > '9'){
			*n = 0;
			return ERR;
		}
		i++;
	}

	if(i==j || (i==j+1 && buff[j]=='-'))
		return ERR;

	buff[i] = '\0';
	for(;j<i;j++){
		int dig = buff[j]-'0';
		*n = ((*n)<<3) + ((*n)<<1) + dig;	
	}
	if(isneg)
		*n = -(*n);		

	return OK;
}

/*fP is the float in %f format ... return value is error*/
int readf(float *f)
{
	int i=0,j=0,isneg=0;
	long long int intgr=0;
	float fraction=0.0f;
	float tensPower=1.0f;
	do
	{
		i=j=0;
		__asm__ __volatile__ (
							"movl $3, %%eax \n\t"
							"movl $0, %%ebx \n\t"
							"int $128 \n\t"
							:
							:"c"(buff)
							) ; 
		while(buff[i] == ' ' || buff[i] == '\t'){
			i++;j++;
		}

	}while(buff[i]=='\n');

	while(buff[i]!='\n' && buff[i]!=' ' && buff[i]!='\t' && buff[i]!='.')
	{
		if(i==j && buff[i]=='-')
		{
			if(isneg){
				*f=0.0;
				return ERR;
			}
			else{
				i++;
				j++;
				isneg=1;
				continue;
			}
		}

		if(buff[i] < '0' || buff[i] > '9')
		{
			*f = 0.0f;
			return ERR;
		}
		i++;
	}

	int decimalpt = j;
	for(;j<i;j++)
	{
		int dig =  buff[j]-'0';
		intgr = (intgr<<3) + (intgr<<1) + dig;
	}
	*f = intgr;
	j = decimalpt;

	if(buff[i] == '\n' || buff[i] == ' ' || buff[i] == '\t')
	{
		if((buff[j]=='-' && (i-j)==1) || (i-j)==0)
		{
			return ERR;
		}
		else if(isneg)
			*f *= -1.0f;
		return OK;

	}

	i++;
	j=i;
	while(buff[i]!='\n' && buff[i]!=' ' && buff[i]!='\t')
	{
		if(buff[i] < '0' || buff[i] > '9')
		{
			*f = 0.0f;
			return ERR;
		}
		i++;
	}

	for(;j<i;j++)
	{
		int dig = buff[j]-'0';
		fraction = fraction*10.0f + (float)(dig);
		tensPower *= 10.0f;
	}
	*f += fraction/tensPower;

	if(isneg)
		*f *= -1.0f;
	return OK;
}

int printd(float f)
{
	int intgr=0;
	int i=0,j=0,bytes;
	char temp;			
	if(f<0){
		f = -f;
		buff[i++] = '-';
		j++;
	}
	intgr = (int)f;
	if(intgr==0){
		buff[i++] = '0';			
		bytes = i;
	}
	else{
		while(intgr){
			buff[i++] = intgr%10+'0';		
			intgr /= 10;
		}
		bytes = i--;
		while(j<i)				
		{
			temp    = buff[i];
			buff[i] = buff[j];
			buff[j] = temp;
			i--;
			j++;
		}
	}
	buff[bytes++] = '.';

	i = j = bytes;
	f -= (int)f;

	for(j=0;j<6;j++){
		f*=10;
		buff[i++] = (int)f + '0';					
		f -= (int)f;
	}
	bytes = i;

	__asm__ __volatile__ (
						"movl $4, %%eax \n\t"
						"movl $1, %%ebx \n\t"
						"int $128 \n\t"
						:
						:"c"(buff), "d"(bytes)
						) ; 
	return bytes;
}
