#include<stdio.h>
int i=0;
void move(char x,char y);
void step(int m,char a,char b,char c);
int main()
{
		int n;
	 	printf("输入塔高：");
		scanf("%d",&n);
		printf("移动的步骤如下：\n");
		step(n,'A','B','C');
		printf("需要移动%d次!\n",i);

		return 0;
}

void move(char x,char y)
{
		printf("%c-->%c\n",x,y);
}

void step(int m,char a,char b,char c)		
{
		if(m==1)
		{
						move(a,c);//只有一层时，直接把方块从a移动到c
						i++;			
		}
		else
		{
				step(m-1,a,c,b);//将m-1个方块从a通过c移到b
				move(a,c);//将最下层的方块直接移到c
				i++;	
				step(m-1,b,a,c);//将m－1块方块从b通过a移到c
				
		}

}
