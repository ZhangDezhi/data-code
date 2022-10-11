#include<stdio.h>
#include<stdbool.h>
int index;
int data[20];
 
int push(int d)//数据入栈
{
		if(index>19)
				return false;
		data[index++] = d;
		return true;
}

int pop(void )//出栈
{
		return data[--index];
}

int top(void)//显示栈顶
{
		return data[index -1];
}

int empty(void)
{
		if(index<0)
				return true;
		else 
				return false;
}

int main()
{
		int i=0;
		for(;i<=20;i++)
				push(i);
		printf("%d\n",pop());
		printf("%d\n",pop());
		printf("%d\n",pop());
		printf("%d\n",pop());
		printf("%d\n",pop());
		printf("%d\n",pop());
		printf("%d\n",pop());
		printf("%d\n",pop());
		printf("%d\n",pop());
		printf("%d\n",pop());
		printf("%d\n",pop());
		printf("%d\n",pop());
		printf("%d\n",pop());
		printf("栈顶：%d\n",top());
		printf("%d\n",pop());
		printf("是%s\n",empty()?"空栈":"非空栈");
		printf("%d\n",pop());

		return 0;
}







