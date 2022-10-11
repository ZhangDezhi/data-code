#include<stdio.h>
int main()
{
		FILE*fp = fopen("ungetc.txt","r");//文件内容：123abc4
		int c;
		for(;;)
		{
				c = getc(fp);
				if(c<'0'||c>'9')
						break;
		}
		ungetc(c,fp);//取回a,不执行这一步，则结果为：bc4
		for(;;)
		{
				c = getc(fp);
				if(c==EOF)
						break;
				peintf("%c",c);
		}
		fclose(fp);

		return 0;
}
