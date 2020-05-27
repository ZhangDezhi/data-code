#include<stdio.h>
#include<time.h>
#define china 10086
int Money;
void save(void);
void take(void);
void search(void);
void change(void);
int out(void);
int main()
{		
		int choice;
		printf("**********欢迎登录帐户界面**********\n");
		printf("*   1.存钱                         *\n");
		printf("*   2.取钱                         *\n");
		printf("*   3.查询                         *\n");
		printf("*   4.转帐                         *\n");
		printf("*   5.退卡                         *\n");
		printf("************************************\n");
	 	printf("请选择您需要办理的业务:(1~5)\n");
loop :	scanf("%d",&choice);
		if(choice != 1&&choice != 2&&choice != 3&&choice !=4 &&choice !=5 )
		{
				printf("没有这个选项,重新选择:");
				goto loop;
		}
		switch(choice)
		{
			case 1:save();break;
			case 2:take();break;
			case 3:search();break;
			case 4:change();break;
			case 5:out();break;
			default:main();
		}
		return 0;
}


void save(void)//存入函数
{
		int t = time (0);
		int a;
		printf("请输入您要存入的金额:(仅限100面额)\n");
loop1:  scanf("%d",&a);//若输入金额错误，跳到loop1重新输入
		if (a%100!=0||a<0)//输入错误的金额
		{
				printf("只提供正百交易,请重新输入!\n");
				goto loop1;
		}
       else{
				Money = Money + a;//存入金额加原有金额
				
				printf("请稍等...\n");
				while (t==time(0));
				printf("存入成功,当前余额为%d元!\n",Money);
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
		int b;
		printf("请输入您要取出的金额:(仅限一百面值)\n");
loop2:	scanf("%d",&b);
		if(b%100!=0||b<0)
		{
				printf("只提供整百交易,请重新输入!\n");
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
						printf("交易成功,您的余额为:%d!",Money);

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
	printf("您的当前余额为%d元!\n",Money);
	printf("请输入任意值返回主菜单!\n");
	int i;
	scanf("%d",&i);
	main();
}


void change(void)
{
	int a;
	printf("请输入您要转入的帐户:");
loop3:	scanf("%d",&a);
	if(a!=china)//判断输入的帐户是否匹配
	{
			printf("不存在此用户，您需要？1：重新输入 其它：返回\n");
			int n;
			scanf("%d",&n);
			switch (n)
			{
					case 1:goto loop3;
					default :main();
			}
			goto loop3;
	}
	printf("请输入您要转入的金额：\n");
	int i;
loop4 :	scanf("%d",&i);
	if(i%100!=0||i<0)
	{
			printf("请输入整百面值：");
			goto loop4;
	}
	else if(i>Money)
	{
			printf("您的余额不足以提供转帐，请重新输入：\n");
			goto loop4;
	}
	Money = Money - i;
	printf("转帐成功，您的当前余额为%d元！\n",Money);
	printf("请选择接下来的操作:1:继续转帐\t其它：返回主菜单\n");
	int j;
	scanf("%d",&j);
	switch(j)
		{
			case 1 :change();break;
			default:main();
		}
}

int out(void)//退出程序
{
		return 0;
}
