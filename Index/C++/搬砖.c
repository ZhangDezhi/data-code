#include<stdio.h>
int main()
{
		int a,b,c,j;
		for(a=1;a<9;a++)//男人
			for(b=1;b<18;b++)//女人
				for(c=2;c<72;c=c+2)
				{	
					if(a+b+c==36&&4*a+3*b+c/2==36)
						printf("有%d个男人%d女人%d个小孩！\n",a,b,c);
				}
		return 0;
}

