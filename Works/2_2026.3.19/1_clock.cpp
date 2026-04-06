/*
一、根据以下的主函数，写出相关的类。
主函数如下：
int main()
{
clock clo1;
cout<<"CLOCK A:"<<endl;
clo1.set(2,30,0); //设置时钟的当前时间
for (int i=0;i<10;i++)
{
	clo1.tick(); //时钟增加1秒
	clo1.show(); //第一次循环打印输出：2:30:1
}
}

*/

#include <iostream>
using namespace std;

class clock{
    public:
    void set(int h,int m,int s);
    void tick();
    void show();
private:
    int hour;
    int minute;
    int second;
};

void clock::set(int h,int m,int s){
    hour=h;
    minute=m;
    second=s;
}

void clock::tick(){
    if(second==59){
        second=0;
        if(minute==59){
            minute=0;
            if(hour==23){
                hour=0;
            }
            else{
                hour++;
            }
        }
        else{
            minute++;
        }
    }
    else{
        second++;
    }
}

void clock::show(){
    cout<<hour<<":"<<minute<<":"<<second<<endl;
}
