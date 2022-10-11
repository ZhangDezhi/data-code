//自己实现printf
#include<stdio.h>
#include<stdarg.h>
#include<string.h>
#include<time.h>
int my_printf(const char*format,...){
	int cn = 0;
	va_list ap;
	va_start(ap,format);
	char c;
	for(c = *format;c;c = *(++format))
			if(c=='%')
					switch(c=*(++format))
					{
						case 'd':
						{			//需要定义局部变量，所以要{}
						int n = va_arg(ap,int);
						char sz[128];
					//	itoa(n,sz);
						sprintf(sz,"%d",n);
						fputs(sz,stdout);
						cn +=strlen(sz);
						break;
						}
						case 'c':
						{
								char c= va_arg(ap,int);
								putchar(c);
								cn++;
								break;
						}
						case 's':
						{
								char *s = va_arg (ap,char*);
								fputs(s,stdout);
								cn += strlen(s);
								break;
						}

					}
			else
			{
				 	putchar(c);
					cn++;
			}
			va_end(ap);
			return cn;
}

int main()
{
		my_printf("hello word%d,%c,%s\n",200,'A',"tarena");		
		
		time_t t = time(NULL);
		struct tm *ptm=localtime(&t);
		printf("%d年%d月%d日,%d:%d:%d",ptm->tm_year+1900,ptm->tm_mon+1,ptm->tm_mday,ptm->tm_hour,ptm->tm_min,ptm->tm_sec);

		return 0;
}
