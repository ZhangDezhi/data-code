#include<stdio.h>
int main()
{
		printf("hello word!\n");//字面值方式		
		char sz1[]= {'A','B','C','\0'};
		printf("%s\n",sz1);
		char sz2[] = "ABC";//实际是将串复制到栈中
		sz2[0] = 'X';//对栈中的串进行修改
		printf("%s\n",sz2);
		char*psz1 = "Tarena";//放在静态存储区中，只读
		//psz1[0] = 'X';//段错误，放入栈中的实际上是Tarena这个串的地址
		int i;
		for(i=0;i<8;i++)
				printf("%d ",psz1[i]);
		psz1 = sz2;
		psz1[0] = 'Y';//
		printf("%s\n",psz1);
		
		return 0;
}
