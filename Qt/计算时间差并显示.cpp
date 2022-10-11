//
//   计算时间差并显示.cpp
//
// Created by ZhangDezhi on2020-07-01 10:33 
// Last Modified  : 2020-07-01 11:26:06
// Copyright © 2020  Zero Ltd. All Right reserved
//
//




    timeb t;
    ftime(&t);
    long long start = t.time*1000  + t.millitm;


    timeb tt;
    ftime(&tt);
    long long end = tt.time*1000  + tt.millitm;


	printTime(start,end);



QString searchThread::printTime(long long start, long long end)
{
    QString rStr ;
    long long ms = end - start;
    if( ms<0) return rStr;
    int ss = 1000;
    int mi = ss * 60;
    int hh = mi * 60;
    int dd = hh * 24;

    long day = ms / dd;
    long  hour = (ms - day * dd) / hh;
    long minute = (ms - day * dd - hour * hh) / mi;
    long second = (ms - day * dd - hour * hh - minute * mi) / ss;
    long milliSecond = ms - day * dd - hour * hh - minute * mi - second * ss;

    rStr = QString("%1天%2时%3分%4秒%5毫秒").arg(day).arg(hour).arg(minute).arg(second).arg(milliSecond);

    return rStr;

}
