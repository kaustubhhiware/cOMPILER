int printi(int num);
int prints(char * c);
int readi(int *eP);

int main()
{
    
    int a,b,x;
    int *e;
    b = 3;
    e = &b;
   
    prints("\nEnter a number \n");
    a = readi(&x);
    prints("Enter another number \n");
    b = readi(&x);    
    prints("The sum is:");
    printi(a+b);

    prints("\nThe difference is:");
    printi(a-b);
    
    prints("\nThe product is:");
    printi(a*b);

    prints("\nThe modulo is:");
    printi(a%b);  
    prints("\n");  
    return 0;
}
