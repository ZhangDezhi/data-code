/*
进栈
出栈
栈顶
判空
*/
#include<stdio.h>
#include<stdbool.h>
int g_data[1024];
size_t g_top=0;
			
size_t capacity(void)//获取栈的容量
{
		return sizeof(g_data)/sizeof(g_data[0]);
}
size_t size(void)//获取栈的大小
{
		return g_top;
}
bool full(void)//判man
{
		return g_top >=capacity();
}
						
bool empty(void)//判空
{
		return g_top == 0;
}

bool push(int data)//进栈
{
		if(full())
				return false;
		g_data[g_top++] = data;
		return true;
}
										
bool pop(void)//出栈，bool表示成功与否
{
		if(empty())
				return false;
		g_top--;
		//return true;
}
							
void clear(void)//清空数据
{
		g_top = 0;
}
int top(void)//获取栈顶
{
		return g_data[g_top-1];
}

void print(unsigned int data,int base)
{
		clear();
		do{
				push(data%base);

		}while (data /= base);
		for(;!empty();g_top--)//pop())
		{
			if(top()<10)
					printf("%d",top());
			else
					printf("%c",top()-10+'A');

		}
		printf("\n");
}



int main()
{
		int i;
		for(i=0;i<10;i++)
		{
				push((i+1)*10);
		}
		while(!empty())
{
				printf("%d\t",top());
				pop();
		}
		printf("\n");
		printf("清输入一个正整数：");
		int data;
		scanf("%d",&data);
		printf("转成几进制？\n");
		int base;
		scanf("%d",&base);
		print(data,base);

		return 0;
}
