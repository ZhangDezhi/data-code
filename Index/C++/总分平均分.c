#include<stdio.h>
int main()
{
		int i,count;
		float score,sum,aver;
		printf("输入学生数：");
		scanf("%d",&count);
		for(i=1;i<=count;i++)
		{
				scanf("%f",&score);
				sum+=score;
		}
		aver = sum/count;
		printf("总分为：%.2f\n",sum);
		printf("平均分：%.2f\n",aver);



		return 0;
}
