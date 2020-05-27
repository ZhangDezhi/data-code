//实现电子时钟类
/*提示：系统时间获取
sleep(1)睡眠一秒
时钟更新时不换行
*/
#include<iostream>
#include<time.h>
using namespace std;
class Time{
public:
		int  show_hour(int t){
				hour = t%(3600*24)/3600+8;
				return hour;
			}
		int  show_min(int t){
				minute = t%3600/60;
				return minute;
		}
		int show_sec(int t){
				second = t%60;
				return second;
		}
private:int hour;
		int minute;
		int second;

};
int main()
{
		Time A;
		while(1){
			int t = time(0);
			cout<<A.show_hour(t)<<":"<<A.show_min(t)<<":"<<A.show_sec(t)<<"\r";
			sleep(1);
			fflush(stdout);
		}
		return 0;
}
