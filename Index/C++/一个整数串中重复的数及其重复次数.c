#include<stdio.h>
int main()
{
		long long int date;
		int a[20]={0},i;
		printf("输入一个整数：\n");
		scanf("%lld",&date);
		do
		{
				a[date%10]++;//date对十求余，求得的值相等时，a[]自加
				date/=10;//整数向右移一位
		}while(date!=0);
		for(i=0;i<=10;i++)
		{
				if(a[i]>1)//选出出现不止一次的数值
						printf("%d重复%d次\n",i,a[i]);
		}


		return 0;
}
