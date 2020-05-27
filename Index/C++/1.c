


#include<stdio.h>
int main()
{
		char a[5]={'a','b','c','d','e'};
		int i,j,out,total=5,num = 4,start = 0;
		for(i=0;i<5;i++)//总共5个人，要出圈5次
		{
				
				if(total==1)//只剩一个人时，直接出圈
						printf("%c",a[0]);
				else
				{
						out = (start+num-1)%total;//下一个出圈的下标
						printf("%c\t",a[out]);
						for(j=out;j<total;j++)//每出一个人，后面的下标向前移动1
								a[j]=a[j+1];
						start = out;//新的初始地点	
						total = total -1;//剩余人数
				}
		}


		printf("\n"); 
		return 0;
}