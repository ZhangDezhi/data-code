/*
输入函数input
输出函数show
退出函数quit
繁殖函数bread
*/
#include<stdio.h>
#include<stdlib.h>
#define H 10//高
#define W 10//宽

void input(char c[][10])//随即输入一组数据
{			
 	srand(time(0));
	//char c[10][10];	
	int i,j;
	for(i=0;i<H;i++)
		for(j=0;j<W;j++)
				c[i][j] = rand()%2?'*':' ';		
}
void show(char c[][10],int g)//数据输出

{
//		char c[10][10];		
		int i,j;
		int n=0;
		for(i=0;i<H;i++)
		{		for(j=0;j<W;j++)
				{
					printf("%c",c[i][j]);
					if(c[i][j]=='*')
							n++;
				}
				printf("\n");
		}
		printf("第%d代有%d个细胞\n",g,n);
}
int quit(void)//退出函数
{
	printf("按q退出，其它键继续\n");
	int ch = getchar();
	if(ch=='q'||ch == 'Q')
		exit(0);
		
}
void bread(char c[][10])//繁殖函数
{
	
//	char c[10][10];
		int i,j;
		for(i=0;i<H;i++)
		{
			for(j=0;j<W;j++)
			{
					int u = i-1,d = i+1,l = j-1,r = j+1,k = 0;
					if(u>=0&&c[u][j]=='*') k++;
					if(d< H&&c[d][j]=='*') k++;
					if(l>=0&&c[i][l]=='*') k++;
					if(r <W&&c[i][r]=='*') k++;
					if(u>=0&&l>=0&&c[u][l]=='*') k++;
					if(u>=0&&r<W&&c[u][r]=='*') k++;
					if(d<H&&l>=0&&c[d][l]=='*') k++;
					if(d<H&&r<W&&c[d][r]=='*') k++;
					if(k==3)
						c[i][j] = '*';
					else if(k!=2)
						c[i][j] = ' ' ;
					
														
			}
					printf ("\n");
				
		}
		 
}

int main()
{
		char c[10][10];
		int g;
		input(c);
		for(g=1;;g++)
		{
				show(c,g);
				quit();
				bread(c);
		}
		return 0;
}

