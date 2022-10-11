/*回文数猜想*/
#include<stdio.h>
//int data;
int input()
{
		int data;
		for(;;)
		{
			printf("清输入一个整数：\n");
			scanf("%d",&data);
			if(data >=10)
						break;	
		}
		scanf("*[^\n]");
		scanf("%*c");
		return data;
}

int reverse(int data)//逆序
{
		int i=0;
		while(data)
		{
				i = i*10 + data%10;
				data = data/10;				
		}
	return i;
}

int ispalin(int data)//判断是不是回文数
{
	/*	int a[10],i=0,j=0;
		while(data)
		{
				a[i] = data%10;
				data = data/10;
				i++;
		}
		while(i!=j)
		{
			if(	a[i-1]=a[j])
			{	
				i--;
				j++;
			}
			else 
					return false;

		}*/
		return data ==reverse(data);
}
int isover(int data)//判断溢出，data
{
	return data <=0||reverse(data) <=10;
}

int main()
{
		int i=0;
		int data;
		data = input();
		printf("data = %d\n",data);
		for(;!isover(data);data += reverse(data))
		{														
				if(!ispalin(data))
					printf("[%d]%d+%d=%d\n",++i,data,reverse(data),data+reverse(data));
				else
				{
						printf("回文数:%d\n",data);
						return 0;
				}
		}		

		printf("找不到会文数!\n");
		return 0;
}
