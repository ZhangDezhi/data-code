#include<stdio.h>
#include<string.h>
int main()
{
	//	char a[20]="zhangfei";
		//char b[20]="guanyu";
		//char c[20]="zhaoyun";
		//char d[20]="machao";
		//char e[20]="huangzhong";
		char f[20];
		fgets(f,20,stdin);//输入20字符以内的字符串
		printf("你输入的:%s\n",f);
		if(strcmp(f,"guanyu\n")==0||strcmp(f,"zhangfei\n")==0||strcmp(f,"zhaoyun\n")==0||strcmp(f,"machao\n")==0||strcmp(f,"huangzhong\n")==0)
				printf("输入的是五虎将之一%s\n",f);
		else
				printf("不是五虎将之一\n");
		return 0;
}
