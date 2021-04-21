
// Qt计算时间的两种方法：

//     QTime elapsed() : ms
//     QTime currentTime() : ms

// C++计算时间的五种方法：
// clock() : ms
// GetTickCount() : ms
// gettimeofday(time_val*, NULL) : us
// QueryPerformanceFrequency(LARGE_INTEGER*) & QueryPerformanceCounter(LARGE_INTEGER*) : us
// time(NULL) : s


#include <QThread>
#include <QTime>
#include <sys/time.h>   //clock, gettimeofday, time
#include <windows.h>    //Sleep, GetTickCount, timeGetTime, QueryPerformanceCounter
#include <QDebug>

//#pragma comment(lib, "winmm.lib") //timeGetTime, 但是这个库Windows或Qt或VS2015都没有自带

const unsigned long SLEEP_TIME_MILL = 1000;

/**
 * QTime的精度为ms级
 */
void calcByQtimeElapsed() {
    QTime time;
    time.start();
    QThread::msleep(SLEEP_TIME_MILL);
    int timeElapsed = time.elapsed();
    qDebug()<<"QTime.start & QTime.elspsed ="<<timeElapsed<<"ms";
}

/**
 * QTime的精度为ms级
 */
void calcByQtimeCurrentTime() {
    QTime startTime = QTime::currentTime();
    QThread::msleep(SLEEP_TIME_MILL);
    QTime stopTime = QTime::currentTime();
    int elapsed = startTime.msecsTo(stopTime);
    qDebug()<<"QTime.currentTime ="<<elapsed<<"ms";
}

/**
 * clock的精度为ms级
 */
void calcByClock() {
    clock_t startTime = clock();
    Sleep(SLEEP_TIME_MILL);
    clock_t endTime = clock();
    clock_t elapsed = endTime - startTime;
    qDebug()<<"clock ="<<elapsed<<"ms";
}

/**
 * GetTickCount的精度为ms级
 */
void calcByTickCount() {
    //返回自开机以来经历的毫秒数
    DWORD startTime = GetTickCount();
    Sleep(SLEEP_TIME_MILL);
    DWORD stopTime = GetTickCount();
    DWORD elapsed = stopTime - startTime;
    qDebug()<<"GetTickCount = "<<elapsed<<"ms";
}

///**
// * timeGetTime的精度为ms级
// * 必须添加Winmm.lib, 否则编译报错undefined reference
// */
//void calcByTimeGetTime() {
//    //返回自开机以来经历的毫秒数
//    DWORD startTime = timeGetTime();
//    Sleep(SLEEP_TIME_MILL);
//    DWORD stopTime = timeGetTime();
//    DWORD elapsed = stopTime - startTime;
//    qDebug()<<"timeGetTime = "<<elapsed<<"ms";
//}

/**
 * gettimeofday的精度为us级
 */
void calcByGetTimeOfDay() {
    struct timeval startTime, stopTime;
    gettimeofday(&startTime, NULL);
    Sleep(SLEEP_TIME_MILL);
    gettimeofday(&stopTime, NULL);
    long elapsed = (stopTime.tv_sec-startTime.tv_sec) * 1000000 + (stopTime.tv_usec - startTime.tv_usec);
    qDebug()<<"gettimeofday ="<<elapsed<<"us";
}

/**
 * QueryPerformanceCounter的精度为us级
 */
void calcByQueryPerformanceCounter() {
    LARGE_INTEGER frequency, startCount, stopCount;
    WINBOOL ret;
    //返回性能计数器每秒滴答的个数
    ret = QueryPerformanceFrequency(&frequency);
    if(ret) {
        ret = QueryPerformanceCounter(&startCount);
    }
    Sleep(SLEEP_TIME_MILL);
    if(ret) {
        QueryPerformanceCounter(&stopCount);
    }
    if(ret) {
        LONGLONG elapsed = (stopCount.QuadPart - startCount.QuadPart) * 1000000 / frequency.QuadPart;
        qDebug()<<"QueryPerformanceFrequency & QueryPerformanceCounter ="<<elapsed<<"us";
    }
}

/**
 * time(NULL)精确度为s级
 */
void calcByTime() {
    time_t startTime = time(NULL);
    Sleep(SLEEP_TIME_MILL);
    time_t stopTime = time(NULL);
    long elapsed = stopTime - startTime;
    qDebug()<<"time(NULL) ="<<elapsed<<"s";
}

int main(int argc, char *argv[])
{
    calcByQtimeElapsed();
    calcByQtimeCurrentTime();
    calcByClock();
    calcByTickCount();
//    calcByTimeGetTime();
    calcByGetTimeOfDay();
    calcByQueryPerformanceCounter();
    calcByTime();
    system("pause");
    return 0;
}
