#include<stdio.h>
int main()
{
				int a,b,c,d,max_1,max_2,max;
				printf("输入四个数字:\n");
				scanf("%d%d%d%d",&a,&b,&c,&d);
				max_1=a>b?a:b;//比较a，b大小，取其大者赋给max_1
				max_2=c>d?c:d;//同上原理，取大者赋给max_2
				max=max_1>max_2?max_1:max_2;//求出最大值，赋给max
				printf("最大的是：%d\n",max);




				return 0;
}
