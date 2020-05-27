#include <stdio.h>
int main()
{
		char p[13]={'A','2','3','4','5','6','7','8','9','x','J','Q','K'};
		char h[4]={'B','R','h','p'};
		char arr[4][13]={{0}};//二维数组全部初始化为0要｛｛0｝｝；！
		
		srand((unsigned)time(0));
	//	int temp=rand();
		int n,i;
		printf("发牌数：");
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			int index1 = rand()%4;
			int index2 = rand()%13;
			if(arr[index1][index2]==0)
			{
					printf("%c%c\t",h[index1],p[index2]);
					arr[index1][index2]=1;
			}
			else if(i>0)
			{		i--;}

		}



		return 0;
}
