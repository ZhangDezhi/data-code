#include<stdio.h>
int main()
{
		int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
		int b[4][3]={12,11,10,9,8,7,6,5,4,3,2,1};
		int c[3][3]={0};;
		int i,j,k;
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
				for(k=0;k<4;k++)
						c[i][j] += a[i][k]*b[k][j];
					
		for(i=0;i<3;i++)
			{	
					for(j=0;j<3;j++)
						printf("%d\t",c[i][j]);
					printf("\n");	
  			}
		return 0;
}
