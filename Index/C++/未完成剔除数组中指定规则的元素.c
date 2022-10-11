#include<stdio.h>

void out(int a[190],int m,int n[])
{
	int i;
	for(i=0;i<190;i++)
	{
			int k = 1;
		 	while(k<=m)
			{
					if(a[i]%n[k-1]!=0)
					{		
						k++;
									
					}
					else
						break;	
			}
			if(k>m)
					printf("%d\n",a[i]);

	}
			

}


int main()
{
		int a[190];
		int i;
		for(i=10;i<200;i++)
				a[i-10] = i;
		printf("对几个数求余？\n");
		int m,j;
		scanf("%d",&m);
		int n[10]={0};
		printf("分别是哪几个数?\n");
		for(j=0;j<m;j++)
			scanf("%d",n);
		printf("10到200以内不能被他们整除的数是：\n");
		out(a,m,n);
		
		return 0;
}
