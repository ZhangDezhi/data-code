#include<stdio.h>
#include<string.h>

int main()
{
		FILE*fp = fopen("fun.txt","w+");
		if(!fp)
		{
				perror("fopen");
				return -1;
		}
		//	fp = stdout; 
		//int a,b,c,d;
		//scanf("%d%d%d%d",&a,&b,&c,&d);
		//fprintf(fp,"%d,%d,%d,%d\n",a,b,c,d);
		//fprintf(fp,"hello\n");
		char a[1024];
		printf("输入字符串：\n");
		gets(a);
		int i;
		for(i = 0;i<strlen(a);i++)
				fprintf(fp,"%c",a[i]+5);
		fclose(fp);

		return 0;
}
