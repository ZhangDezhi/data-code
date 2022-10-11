#include<stdio.h>
int main()
{
	//	float interest[10];
		int i,n;
		float m,l,j;
		float interest[10];
		printf("请输入最低利率：\n");
		scanf("%f",&l);
		m = l*100;//；将利率转化为百分比值
		printf("m=%.0f\n",m);
		printf("请输入存储年限：\n");
		scanf("%d",&n);
		for(i=0;i<5;i++)//给本金赋初值
				interest[i]=100;
		printf("year\t%.1f%\t%.1f%\t%.1f%\t%.1f%\t%.1f%\t",m,m+1,m+2,m+3,m+4);
		for(i=0;i<n;i++)//年份
			{	 
					printf("\n%d\t",i+1);//换行后更新年份
					int j;
					for(j=0;j<5;j++)//每一行输出5个数值
					{
							interest[j]+=interest[j]*(m+j)/100;//本金等于前年本金与利息的和
							printf("%.2f\t",interest[j]);
					}
					
			}
		printf("\n");


		return 0;
}
