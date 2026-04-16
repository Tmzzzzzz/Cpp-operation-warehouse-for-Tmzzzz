/*
三、设计一个时间类，可以表示含小时、分、秒的时间，如“20:50:12”。
在此基础上，再设计一个日期类，可表示含年、月、日及小时、分、秒的时间，如“2020-01-20 20:50:12”。
在主函数中创建这两个类的实例，并打印输出时间。
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Time {
    private:
        int hour;
        int minute;
        int second;
    public:
        Time(int h,int m,int s):hour(h),minute(m),second(s){}
        void showTime() const {
            cout << setfill('0') << setw(2) << hour << ":"
                 << setfill('0') << setw(2) << minute << ":"
                 << setfill('0') << setw(2) << second;
        }
};

class Date_time{
    private:
        int year;
        int month;
        int day;
        Time time;
    public:
        Date_time(int y,int m,int d,int h,int min,int s):year(y),month(m),day(d),time(h,min,s){}
        void showDate_time() const {
            cout << year << "-" << setfill('0') << setw(2) << month << "-" << setfill('0') << setw(2) << day << " ";
            time.showTime();
        }
};

int main(){
    Time t(20,50,12);
    Date_time dt(2020,1,20,20,50,12);
    t.showTime();
    cout << endl;
    dt.showDate_time();
    return 0;
}