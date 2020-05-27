//
#include<stdio.h>
//闰年
#define ISLEAP(y)  ((y)%4==0&&(y)%100!=0||(y)%400==0)
//小月
#define ISSMALL(m) ((m)==4||(m)==6||(m)==9||(m)==11)
//获得一个月的天数（不考虑2月）
#define NORMAL(m) (ISSMALL(m)?30:31)
//获得某年某月的天数
#define DAYS(y,m) ((m)==2?28+ISLEAP(y):NORMAL(m))
//判断x是否位于[from,to]区间内
#define IN(x,f,t) ((x)>=(f)&&(x)<=(t))
//判断一个日期是否合法
#define VALID(y,m,d) ((y)>0&&IN(m,1,12)&&IN(d,1,DAYS(y,m)))
int main(int argc,char*argv[])
{
	if(argc<4){
			printf("使用：%s<年><月><日>\n",argv[0]);
			return -1;
	}
	int y = atoi(argv[1]);
	int m = atoi(argv[2]);
	int d = atoi(argv[3]);
	if(VALID(y,m,d))
			printf("%d-%d-%d是一个合法日期。\n",y,m,d);
	else
			printf("%d-%d-%d是一个非法日期。\n",y,m,d);
		return 0;
}

