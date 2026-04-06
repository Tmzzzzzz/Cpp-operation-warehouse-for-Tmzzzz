/*
四、定义一个时钟类Clock，用于表示由小时、分、秒组成的时间，并支持以下程序的运行。

主函数如下：
int main()
{
Clock c(10,12,24);  //初始化为10点12分24秒
    c.tick();            //秒针走一秒
	c.print(“hh点mm分ss秒”); //打印输出：10点12分25秒
    c.print(“hh-mm-ss”); //打印输出：10-12-25
	c.print(“hh:mm:ss”); //打印输出：10:12:25
c.print(“hh:mm”);     //打印输出：10:12
c.print(“mm:ss”);     //打印输出：12:25

}
*/
#include <iostream>
#include <string>
using namespace std;

class Clock{
    private:
    int hour;
    int minute;
    int second;
    public:
    Clock(int h,int m,int s):hour(h),minute(m),second(s){}
    void tick(){
        second++;
        if(second==60){
            second=0;
            minute++;
        }
        if(minute==60){
            minute=0;
            hour++;
        }
        if(hour==24){
            hour=0;
        }
    }
    void print(const string& f){
        string str=f;
        size_t pos = str.find("hh");
        if(pos!=string::npos){
            str.replace(pos,2,to_string(hour));
        }
        pos=str.find("mm");
        if(pos!=string::npos){
            str.replace(pos,2,to_string(minute));
        }
        pos=str.find("ss");
        if(pos!=string::npos){
            str.replace(pos,2,to_string(second));
        }
        cout<<str<<endl;
    }
};

int main()
{
Clock c(10,12,24);  //初始化为10点12分24秒
    c.tick();            //秒针走一秒
	c.print("hh点mm分ss秒"); //打印输出：10点12分25秒
    c.print("hh-mm-ss");  //打印输出：10-12-25
	c.print("hh:mm:ss");  //打印输出：10:12:25
    c.print("hh:mm");     //打印输出：10:12
    c.print("mm:ss");     //打印输出：12:25
}
