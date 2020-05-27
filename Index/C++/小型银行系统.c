/*
清空余额
存
取
显示余额
结息
调息
退出*/
#include <stdio.h>
float Money;
float interest = 0.03;
 void clean(void);
void save(void);
void take(void);
void search(void);
void get_inter(void);
void change_inter(void);
int out(void);
int main()
{		
		int choice;
		printf("**********欢迎登录帐户界面**********\n");
		printf("*   1.清空                         *\n");
		printf("*   2.存钱                         *\n");
		printf("*   3.取钱                         *\n");
		printf("*   4.查询                         *\n");
		printf("*   5.结息                         *\n");
		printf("*   6.调息                         *\n");
		printf("*   0.退出                         *\n");
		printf("************************************\n");
	 	printf("请选择您需要办理的业务:(1~5)\n");
loop :	scanf("%d",&choice);
		if(choice != 1&&choice != 2&&choice != 3&&choice !=4 &&choice !=5&&choice !=6&&choice !=0 )
		{																
				printf("没有这个选项,重新选择:");
				goto loop;
		}
		switch(choice)
		{
			case 1:clean();break;
			case 2:save();break;
			case 3:take();break;
			case 4:search();break;
			case 5:get_inter();break;
			case 6:change_inter();break;
			case 0:quit();break;
			default:main();
		}
		return 0;
}


void save(void)//存入函数
{
		int t = time (0);
		float a;
		printf("请输入您要存入的金额:\n");
loop1:  scanf("%f",&a);//若输入金额错误，跳到loop1重新输入
		if (a<0)//输入错误的金额
		{
				printf("输入错误，请重新输入!\n");
				goto loop1;
		}
       else{
				Money = Money + a;//存入金额加原有金额
				
				printf("存入成功,当前余额为%.2f元!\n",Money);
			}
	   printf("请选择接下来的操作：1：继续存入\t2：返回主菜单\n");
	   int i;
	   scanf("%d",&i);
	   switch(i)
	 	{
				case 1:save();break;//继续存钱
				default:main();//跳回主菜单
		}		
}

void take(void)
{
		float b;
		printf("请输入您要取出的金额:\n");
loop2:	scanf("%f",&b);					
		if(b<0)
		{
				printf("输入错误，请重新输入!\n");
				goto loop2;
		}
		else if(b>Money)//余额不足，重新输入
		{
				printf("对不起,您的余额不足,请重新输入!\n");
				goto loop2;
		}
		else
				{
						Money = Money -b;//扣除取出的金额
						printf("交易成功,您的余额为:%.2f!",Money);
														
				}
		printf("请选择接下来的操作：1：继续取出\t其它：返回主菜单");
	    int i;
	    scanf("%d",&i);
	    switch(i)
	 	{
				case 1:take();break;
				default:main();
		}		

}

void search(void)
{
	printf("您的当前余额为%.2f元!\n",Money);
	printf("请输入任意值返回主菜单!\n");
	int i;
	scanf("%d",&i);
	main();
}

void clean()
{
		Money = 0;
			printf("已清零，当前余额:0!\n");
		main();
}

void get_inter(void)

{
		printf("存入年限：");
		float Interest=Money;
		int year;
		scanf("%d",&year);
		int i ;
		for(i = 0;i<year;i++)
		{
				Interest += Money*interest;
				
		}
	printf("您将获得的利息与本金总和为：%.2f元！\n",Interest);		
	main();
}
void change_inter()
{
		printf("您要将利率改为：\n");
		scanf("%f",&interest);
		printf("更新：\n利率边更为%.2f\n",interest);
		
		main();
}
int  quit(void)
{
		return 0;
}

