#include<stdio.h>
int main()
{
		int m,n,i,k;
		printf("输入两个整合：\n");
		scanf("%d%d",&m,&n);
		k = n<m?n:m;
		for(i=k;i>0;i--)//求最大公约数
		{
				if(n%i==0&&m%i==0)
					{
							printf("%d和%d的最大公约数是：%d\n",m,n,i);
							break;//得出最大公约数后跳出循环
					}
		}
		k = m*n/i;
		printf("最小公倍数为：%d\n",k);
		k = m>n?m:n;
		for(i=m;i<=m*n;i++)
			{
					if(i%m==0&&i%n==0)
					{
							printf("%d和%d的最小公倍数是:%d\n",m,n,i);
							break;
					}
			}



		return 0;
}
