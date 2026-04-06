/*
五、请编写一个程序用于判断两个矩形的拓扑关系（相离、相交、包含）。
*/

#include <iostream>
using namespace std;
class rectangle{
    private:
    int x1;
    int x2;
    int y1;
    int y2;
    public:
    rectangle(){
        x1=y1=x2=y2=0;
    }
    void set(int a,int b,int c,int d){
        x1=a;
        x2=b;
        y1=c;
        y2=d;
        if(x1>x2)swap(x1,x2);
        if(y1<y2)swap(y1,y2);
    }
    int left(){return x1;}
    int right(){return x2;}
    int top(){return y1;}
    int bottom(){return y2;}
};

class check{
    public:
    bool isSeparation(rectangle r1,rectangle r2){
        return(r1.left()>r2.right()||r1.right()<r2.left()||r1.top()<r2.bottom()||r1.bottom()>r2.top());
    }
    bool isInclude(rectangle r1,rectangle r2){
        if(r1.left()>=r2.left()&&r1.right()<=r2.right()&&r1.top()<=r2.top()&&r1.bottom()>=r2.bottom()){
            return true;
        }
        if(r2.left()>=r1.left()&&r2.right()<=r1.right()&&r2.top()<=r1.top()&&r2.bottom()>=r1.bottom()){
            return true;
        }
        return false;
    }
    bool isCross(rectangle r1,rectangle r2){
        return !isSeparation(r1,r2)&&!isInclude(r1,r2);
    }
};

int main(){
    rectangle r1,r2;
    int x1,x2,y1,y2;
    cout<<"第一个矩形(依次为左右上下坐标)"<<endl;
    cin>>x1>>x2>>y1>>y2;1 =
    r1.set(x1,x2,y1,y2);
    cout<<"第二个矩形"<<endl;
    cin>>x1>>x2>>y1>>y2;
    r2.set(x1,x2,y1,y2);
    check c;
    if(c.isSeparation(r1,r2)){
       cout<<"相离"<<endl;
    }else{
        cout<<"不相离"<<endl;
    }
    if(c.isInclude(r1,r2)){
        cout<<"包含"<<endl;
    }else{
        cout<<"不包含"<<endl;
    }
    if(c.isCross(r1,r2)){
        cout<<"相交"<<endl;
    }else{
        cout<<"不相交"<<endl;
    }
    return 0;
}