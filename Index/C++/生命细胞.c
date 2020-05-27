/*生命细胞*/
#include<stdio.h>
#include<stdlib.h>
#define H 10 	//高度
#define W 10	//宽度
	

void init (char c[][W])//初始化细胞群落
{	
	srand(time(NULL));//设置随机种子
	int i,j;
	for(i=0;i<H;i++)
			for(j=0;j<W;j++)
					c[i][j] = rand()%2?'*':' ';
}

void show (char c[][W],int g)//显示细胞群落,g表示繁殖代数
{
		int i,j,k=0;
		for(i=0;i<H;i++)
			{
					for(j=0;j<W;j++)
			{	
					printf("%c",c[i][j]);
				if(c[i][j]=='*')
					k++;
			}
			printf("\n");
			}
			printf("第 %d代有%d 个活细胞。\n",g,k);
}

int quit(void)//接受用户的选择，按任意键继续，q退出
{
		printf("按q退出，其它键继续\n");
		int ch = getchar();
		if(ch == 'q'||ch =='Q')
				exit(0);//退出整个进程
}

void breed(char c[][W])//繁殖
{
	int i,j;
	for(i=0;i<H;i++)
			for(j=0;j<W;j++)
				{
						int u=i-1,d=i+1,l= j-1,r=j+1,k=0;
						if(u>=0&&c[u][j]=='*')
								k++;
						if(d<H &&c[d][j]=='*')
								k++;
						if(l>=0&&c[i][l]=='*')
								k++;
						if(r<W&&c[i][r]=='*')
								k++;
						if(u>=0&&l>=0&&c[u][l]=='*')
								k++;
						if(u>=0&&r<W&&c[u][r]=='*')
								k++;
						if(d<H&&l>=0&&c[d][l]=='*')
								k++;
						if(d<H&&r<W&&c[d][r]=='*')
								k++;
						if(k==3)
								c[i][j]='*';
						if(k!=2)
								c[i][j]=' ';

				}

}


int main()
{
	char c[H][W];
	init(c);
	int g;
	for(g=1;;g++)
	{
			show(c,g);
			quit();
			breed(c);
	}

	return 0;
}
