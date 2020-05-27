#include<stdio.h>
aut swap(int &i,int &b)
{
		aut temp;
		temp = i;
		i =b;
		b = temp;
		printf("temp= %d",temp);
		return 0;
}

int main()
{
		int &i=1,&j=2;
	//	i = 1,j= 2;
		printf("交换前i = %d,j = %d\n",i,j);
		swap(i,j);
		printf("交换前i = %d,j = %d\n",i,j);


		return 0;
}
