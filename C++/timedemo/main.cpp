#include <iostream>
#include<sys/timeb.h>

char*  printTime(long long start, long long end)
{
    char rStr[1024]={0};

    long long ms = end - start;
    if( ms<0) return rStr;
    int ss = 1000;
    int mi = ss * 60;
    int hh = mi * 60;
    int dd = hh * 24;

    long day = ms / dd;
    long hour = (ms - day * dd) / hh;
    long minute = (ms - day * dd - hour * hh) / mi;
    long second = (ms - day * dd - hour * hh - minute * mi) / ss;
    long milliSecond = ms - day * dd - hour * hh - minute * mi - second * ss;

    sprintf(rStr,"%ld 天 %ld 时 %ld分 %ld 秒 %ld 毫秒\n",day,hour,minute,second,milliSecond);

    return rStr;

}

int main() {

    std::cout << "Start" << std::endl;

    timeb t;
    ftime(&t);
    long long start = t.time*1000  + t.millitm;
    long searchnum = 0;
    _sleep(5*1000);//延时5s
    _sleep(5*100);//延时5s

    timeb tt;
    ftime(&tt);
    long long end = tt.time*1000  + tt.millitm;
    printf("%s",     printTime(start,end));



    return 0;
}

