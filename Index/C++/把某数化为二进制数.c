#include <stdio.h>
int main()
{
	int i,n;
	int r;
	printf("输入一个整数：\n");
	scanf("%d",&i);
	for(n=16;n>0;n--)
		{
			r = i>>(n-1) & 1 ;/*向右移位n-1并与1相与
							求得倒数第n位的进制位值*/
			printf("%d",r);//从右到左依次输出二进制数值
		}
	printf("\n");
	return 0;
}
