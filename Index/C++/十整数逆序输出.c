#include<stdio.h>
int main()
{
		int a[10],i;
		printf("请输入十个整数：\n");
		for(i=0;i<10;i++)
			scanf("%d",&a[i]);
		for(i=9;i>=0;i--)
				printf("%d\n",a[i]);


		return 0;
}
