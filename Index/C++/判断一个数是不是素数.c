#include<stdio.h>
#include<stdbool.h>
int odd(int a)
{
		int i;
		for(i=2;i<a;i++)
				if(a%i==0)
						return false;
		return true;

}

int main()
{
		int a;
		printf("请输入一个整数：\n");
		scanf("%d",&a);
		printf("%s\n",odd(a)?"素数":"合数");
			
		return 0;
}
