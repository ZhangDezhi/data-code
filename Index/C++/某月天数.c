#include<stdio.h>
int main()
{
	int year,month;
	printf("输入年月：\n");
	scanf("%d%d",&year,&month);
	if (month==4||month==6||month==9||month==11)//4.6..9.11月有30天
		printf("%d年%d月有30天！\n",year,month);
	else if(month!=2)
		printf("%d年%d月有31天！\n",year,month);//其他出了2月，都有31天
	else if(month==2)//闰年2月有29天，平年2月有28天
	{
		if(year%4==0&&year%100||year%400==0)
			printf("%d年%d月有29天！\n",year,month);
		else 
			printf("%d年%d月有28天！\n",year,month);
	}

	return 0;
}

