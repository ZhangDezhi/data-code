#include<stdio.h>
int fee_gui(int n)
{
		if(n<3)
				return 1;
		return fee_gui(n-1)+fee_gui(n-2);
}


int fee_tui(int n)
{
	int x = 1,y = 1,i;
	for(i = 3;i <=n;i++)
	{
			y = x + y;
			x = y - x;
	}
		return y;
}


int main()
{
	//	printf("递归：%d\n",fee_gui(45));
		printf("递推：%d\n",fee_tui(45));


		return 0;
}
