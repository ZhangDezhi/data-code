/*
split(const char *psz,const char *sep)函数
实现psz ＝ “Tarena@com.cn"
分为sep = "@."
Tarena
com
cn
*/
#include<stdio.h>
#include<string.h>
void split(const char*psz,const char *sep)
{
	char sz[strlen(psz)+1];
	strcpy (sz,psz);
	char *p1 = NULL,*p2 = NULL;
	for(p2 = sz;*p2;p2++)
	{
			for(;*p2&&strchr(sep,*p2);p2++);//p2指向有效字符或到字符串尾
			if(!*p2)
					break;
			p1 = p2;//p1指向第一个有效字符
			for(;*p2&&!strchr(sep,*p2);p2++);//找到分割符
			if(!*p2)
			{
					puts(p1);
					break;
			}
			*p2 = '\0';//p2
			puts(p1);
	}
}

/*	char *token = NULL;
	for(token = strtok(sz,sep);token;token=strtok(NULL,sep))
			puts(token);
}
*/
int main()
{
		char str[1024],sep[128];
		printf("请输入一个字符串：\n");
		gets(str);
		printf("请输入分隔符串：");
		gets(sep);
		split(str,sep);
		return 0;
}
