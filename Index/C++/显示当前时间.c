#include<stdio.h>
#include<time.h>
int main()
{
		int t=0;//将当前时间赋值给t
		
		int h=0,m=0,s=0;
		while(1)
		{
			t = time(0);
			s = t%60;//秒
			m = t%3600/60;//分
			h = t%(24*3600)/3600;//小时
			printf("%2d:%2d:%2d\r",h+8,m,s);
			fflush(stdout);
			while(t==time(0));
		}
		return 0;
}
