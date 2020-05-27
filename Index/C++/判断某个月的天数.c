#include<stdio.h>
int main()
{
				int m,y;
				printf("输入一个月份：\n");
				loop:scanf("%d",&m);
				if(m==2)//2月天数存在闰平年区别
				{
								printf("请输入今年年份：\n");
								scanf("%d",&y);
								if((y%4==0&&y%100!=0)||y%400==0)
												printf("此年份下二月有29天！\n");
								else
												printf("此年份下二月有28天!\n");
				}
				else if(m==4||m==6||m==9||m==11)//4,6,9,11月有30天
								printf("%d月有30天！\n",m);
				else if(m==1||m==3|m==5||m==7||m==8||m==10||m==12)
								printf("%d月有31天！\n",m);
				else 
				{
								printf("不存在%d月!请重新输入：\n",m);
								goto loop;//goto 语句跳到输入行
				}								




				return 0;
}
