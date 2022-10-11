#include<stdio.h>
int main()
{				
				int i,total,a[20];
				a[0] = 1;
				i=0;
				printf("输入上限：\n");
				scanf("%d",&total);
				printf("第%d个砝码重：%d\n",i+1,a[i]);
				do//do循环输出每一个砝码重
				{
								++i;
								a[i]=a[i-1]+a[i-1];//根据计算，后一个砝码其实是前一个砝码的2倍
								printf("第%d个砝码重：%d\n",i+1,a[i]);
								
				}
				while(2*a[i]-1<total);//上限是2a[i]-1
				


				return 0;

}
