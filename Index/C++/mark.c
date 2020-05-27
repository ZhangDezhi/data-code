#include<stdio.h>
#include<stdarg.h>
int max(int max,...)
{
		va_list ap;
		va_start (ap,max);
		int n;
		while((n = va_arg(ap,int ))!=-1)
				if(n>max)
						max = n;
		va_end(ap);
		return max;
}

int main()
{
		printf("%d\n",max(10,-1));
		printf("%d\n",max(17,20,-1));
		printf("%d\n",max(23,29,40,-1));
		printf("%d\n",max(12,54,2,64,21,65,23,5,324,321,5,2,-999,-1));




		return 0;
}
