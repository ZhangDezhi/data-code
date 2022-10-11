#include<stdio.h>
int main()
{
				int i,total,a[20];
				a[0] = 1;
				i = 0;
				printf("输入上限:");
				scanf("%d",&total);
				printf("第%d个砝码重：%d\n",i+1,a[i]);
				if((2*a[i])<=total)
				{
					for(i=1;;i++)
							{
											a[i]=2*a[i-1];
											printf("第%d个砝码重：%d\n",i+1,a[i]);
							}
				}
						


				return 0;
}

