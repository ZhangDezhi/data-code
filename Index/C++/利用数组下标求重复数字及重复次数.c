/*#include<stdio.h>
int main()
{
	long long a;			//长长型，可以表示19位以内的数
	int n,i,j,x[100];
	i=0;
	printf("输入一个整数：\n");
	scanf("%lld",&a);
	do 				//(a!=0)		//得出这个整数每一位的数值
	{
		n = a%10;
		x[i] = n;
		++i;	
		a = a/10;
	}while(a);
	printf("这个数有:\n");
	for(a=i-1;a>=0;a--)	//从左边开始读数值
		{
				j=1;
				for(n=0;n<a;n++)  //将读出的值一一与其右边所有的值比较
					if(x[a]==x[n]&&x[n]>=0)
						{		x[n]=-1;	//将已经选出的值提出队列
								j++;
						}			//
				if(j!=1&&x[a]>=0)
							printf("\t%d个%d\n",j,x[a]);
		}



	return 0;

}*/



#include<stdio.h>
int main()
{
		int a[20]={0};
		long long	int data;
		printf("请输入一个整数：");
		scanf("%lld",&data);
		int i,j=0;
		while(data)
		{
				a[data%10]++;//数出现一次，以其作为下标的数组加一
						data=data/10;
				j++;
		}
		for(i=0;i<j;i++)
				if(a[i]>1)
						printf("%d重复  %d次\n",i,a[i]);
		return 0;
}
