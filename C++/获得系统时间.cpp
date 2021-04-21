/*C program to get current system date and time in Linux.*/
 
#include <stdio.h>
#include <time.h>
 
int main()
{
    time_t T= time(NULL);
    struct  tm tm = *localtime(&T);
     
    printf("System Date is: %02d/%02d/%04d\n",tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("System Time is: %02d:%02d:%02d\n",tm.tm_hour, tm.tm_min, tm.tm_sec);

// System Date is: 13/03/2014
//     System Time is: 12:40:59

    timeval tp;
    gettimeofday(&tp, 0);
    time_t curtime = tp.tv_sec;
    tm *t = localtime(&curtime);
    printf("%02d:%02d:%02d:%03d\n", t->tm_hour, t->tm_min, t->tm_sec, tp.tv_usec/1000);
 
    return 0;
}






 
string getTime()
{
    time_t timep;
    time (&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S",localtime(&timep));
    return tmp;
}
 
int main(){
    string   time = getTime();
    cout << time << endl;
 
    return 0;
}










