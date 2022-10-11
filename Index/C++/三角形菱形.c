#include<stdio.h>
int main()
{
		int j,i,n;
		for(i=1;i<=5;i++)
			{		
					for(j=0;j<i;j++)
						printf("*");
					printf("\n");	
			}	
		for(i=0;i<5;i++)
		{	 
			    for(j=0;j<4-i;j++)
			  		printf(" ");
				for(n=0;n<2*i+1;n++)
				  printf("*");
				  printf("\n");
		}
		for(i=4;i>0;i--)
		{
				for(j=0;j<5-i;j++)
						printf(" ");
				for(n=0;n<2*i-1;n++)
						printf("*");
				printf("\n");
		}



		return 0;
}
