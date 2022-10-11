/*尝试自己编写*/
#include<stdio.h>

int input()//数据输入
{
		int data;
		for(;;)
		{
				printf("请输入一个整数:\n");
				scanf("%d",&data);
				if(data>=10)
						break;
		}
        scanf("*[^\n]");
		scanf("%*c");
		return data;
}

int reverse(int data)//逆序
{
		int i=0;
		while(data>0)
		{
			i = i*10+data%10;
			data = data/10;	
		}
		return i;
}

int ispalin(int data)//判断是否为回文数
{
		return data == reverse(data);
}
 int isover(int data)//判断溢出
 {
		 return data<=0||reverse(data)<=10;
 }

 int main()
 {
		int i=0;
		int data = input();
		for(;! ispalin(data);data += reverse(data))
		{	
				 printf("[%d] %d+%d=%d\n",++i,data,reverse(data),data+reverse(data));
				if(isover(data))
				{
					printf("溢出，为找到回文数!\n");		
					return 0;		
				}
		}	
	printf("回文数是%d\n",data); 
	
		//	printf("回文数为:%d\n",data);
		

		 return 0;
 }
