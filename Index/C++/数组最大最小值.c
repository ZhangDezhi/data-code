#include<stdio.h>
void max_min(int a[],int length,int *max,int *min)
{
		int Max = a[0],Min =a[0];
		int i;
		for(i=0;i<length;i++)//遍历数组
		{
				Max = Max > a[i]?Max:a[i];//最大
				Min = Min < a[i]?Min:a[i];
		}
		*min = Min; //赋值给指针
		*max = Max;
}
  

int main()
{
		int a[20];
		int length;
		printf("请输入整数个数：\n");
		scanf("%d",&length);
		printf("请输入%d个整数：\n",length);
		int i;
		for(i=0;i<length;i++)
		{
				scanf("%d",&a[i]);
		}
		int *max =a;
		int *min = &a[length-1];
		max_min(a,length,max,min);//调用函数
		printf("最大值为:%d\n",*max);
		printf("最小值为:%d\n",*min);
		return 0;
}
