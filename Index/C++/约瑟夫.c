#include<stdio.h>
int main()
{
		int people;
		printf("请输入数量：");
		scanf("%d",&people);
		int a[people];
		int i;
		for(i=0;i<people;i++)
				a[i] = i+1;
		int num,out,start,j,total = people;
		printf("请输入间隔:");
		scanf("%d",&num);
		printf("从第几个数字开始?");
		scanf("%d",&start);
		for(i = 0;i<people;i++)
		{
			if( people == 1)
					printf("%d\n",a[0]);
			else
			{
					out = (start + num -1)%total;
					printf("%d\t",a[out]);
					for(j = out;j<people;j++)
							a[j] = a[j+1];
					start = out;
					total--;
			}
			printf("\n");


		}



		return 0;
}
