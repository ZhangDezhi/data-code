#include<stdio.h>

int main()
{
	int i=0,k=0;
	printf("input a num between 1000 and 9999!\n");
	scanf("%d",&i);
	while(i!=0)	//判断是否为四位数
	{
		if(i<1000||i>9999){
		printf("Please input the right num!\n");
		}
		else break;
	}
	while(i!=0)
	{
 		k=k*10+i%10; //将低位数转向高位数，实现逆序
 	    i=i/10;
	}
	printf("After the program ,the num is :%d\n",k);

	return 0;
}
