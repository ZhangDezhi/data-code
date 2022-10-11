#include<stdio.h>
#include<string.h>
int main()
{
		char c;
		FILE*fp = fopen("fun.txt","r+");
		if(!fp)
		{
			perror("fopen");
			return-1;
		}
		while((c = fgetc(fp))!=EOF)
			{
				if (c != '\n')
				{c = c+5;
				fseek(fp,-sizeof(c),SEEK_CUR);
				fputc(c,fp);
				}
			}
		return 0;
}
