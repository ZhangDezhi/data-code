#include<stdio.h>
int main()
{
		int a,i,j,n = 0;
	//	printf("请输入上限：\n");
	//	scanf("%d",&a);
		for(i=2;i<=200;i++)//	遍历上限值以内所有整数
		{
			for(j=2;j<=(i/2);j++)//判断整数是否是素数
				if(i%j==0)
					break;
			if(j>i/2)
				{
						printf("%d\t",i);
						++n;
						if(n%10==0)printf("\n");
				}
		}
		return 0;			
}
