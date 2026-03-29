/*
二、某杯子可以装水，初始时杯中存有一些水，且杯子有最大容量（单位：升）限制。请编写一个杯子类，并编写一个主函数，演示以下功能：往杯子中加水，每次随机添加一定体积的水，当水杯满时，则结束加水，否则可以继续加水。程序要输出一共加了几次水、每次加了多少升水。
输入：初始存水量、最大容量
输出：每次加了多少水、一共加了几次水

输入样例1：1  10
输出样例1：第1次加水：1升
第2次加水：3升
第3次加水：2升
第4次加水：3升
总共加水次数：4次

输入样例2：10  10
输出样例2：总共加水次数：0次

输入样例3：-2  10
输出样例3：第1次加水：7升
第2次加水：3升
总共加水次数：2次
*/

#include <iostream>
#include <ctime>
using namespace std;

class Cup{
    private:
        int limit;
        int now;
        int count;
    public:

        Cup(int ini,int lim){
            limit=lim;
            if(ini<0){
                now=0;
            }else{
                now=ini;
            }
            count=0;
            srand(time(NULL));
        }

        void addWater(){
            int add=1+rand()%limit;
            if(now+add>limit){
                add=limit-now;
            }
            if(add){
                now+=add;
                count++;
                cout<<"第"<<count<<"次加水："<<add<<"升"<<endl;
            }
        }

        bool isFull(){
            if(now==limit){
                cout<<"总共加水次数："<<count<<"次"<<endl;
                return true;
            }else{
                return false;
            }
        }
};

int main(){
    int lim;
    int ini;
    cin>>ini>>lim;
    Cup cup(ini,lim);
    while(!cup.isFull()){
        cup.addWater();
    }
}