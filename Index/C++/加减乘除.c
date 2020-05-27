#include<stdio.h>
int main(int argc,char*argv[])
{
		if(argc<4){
				printf("使用：%s<x><+-*/%><b>\n",argv[0]);
				return -1;
		}
		int res;

	switch(argv[2][0])
	{
		case '+':
			res = atoi(argv[1])+atoi(argv[3]);
			break;
		case '-':
			res = atoi(argv[1])-atoi(argv[3]);
			break;
		case 'X':
			res = atoi(argv[1])*atoi(argv[3]);
			break;
		case '/':
			res = atoi(argv[1])/atoi(argv[3]);
			break;
		case '%':
			res = atoi(argv[1])%atoi(argv[3]);
			break;
		default:
		printf("非法运算符！\n");
		return -1;

	}



		return 0;
}
