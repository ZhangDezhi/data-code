//迷你记事本
#include<stdio.h>
#include<string.h>
int main()
{
		printf("===========\n");
		printf("   记事本\n");
		printf("===========\n");
		char thing[31][1024] = {0};
		int data;
		for(;;)
		{
			printf("备忘事件：");
			scanf("%d",&data);
			if(data==0)
					break;
			 else if(data<0||data>31)
					{
							printf("请输入正确的日期！\n");
							continue;
					}
			else
			{
				scanf("%s",thing[data-1]);
			}

		}
		
		printf("==========\n");
		printf(" 显示信息\n");
		printf("==========\n");
		int i;
		for(i=0;i<31;i++)
				if(strlen(thing[i]))
						printf("%d日：%s\n",i+1,thing[i]);
		return 0;
}
