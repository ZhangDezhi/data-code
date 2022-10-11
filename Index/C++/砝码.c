#include<stdio.h>
int main()
{
		int count = 0,sum = 0,arr[20];
		int i,j;
		for(i=1;i<=100;i++)
		{				
			if(i<=sum);//如果砝码值小于前几个砝码总和，则不为砝码数组赋值
			else//求出下一个砝码的重量
			{
					sum +=i;
					arr[count]=i;
					count++;

			}
		}
		for(j=0;j<count;j++)
				printf("%d\t",arr[j]);




		return 0;
}
