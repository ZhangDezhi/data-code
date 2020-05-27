#include<stdio.h>
int main()
{
				int salary;
				printf("请输入工资：\n");
				scanf("%d",&salary);
				if(salary>=10000)
								printf("乘坐飞机\n");
				else if(salary>=5000)
								printf("乘坐火车\n");
				else if(salary>=3000)
								printf("乘坐汽车\n");
				else if(salary>=1500)
								printf("乘坐自行车\n");
				else
								printf("11路，你懂的\n");



				return 0;

}

