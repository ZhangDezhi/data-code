#include<stdio.h>
void swap(char**a,char**b)
{
		char *c = *a;
		*a = *b;
		*b = c;
}

int main()
{
		char *a = "hello";
		char *b = "world";
	    paintf("%s,%s\n",a,b);//hello, world
		swap(&a,&b);
		printf("%s,%s\n",a,n);//world, hello

		return 0;
		
}
