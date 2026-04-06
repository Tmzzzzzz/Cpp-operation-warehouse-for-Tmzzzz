/*
四、	某多项式的形式为 ax^m+bx^n+c，请编写程序求多项式的值。
输入：x, a, b, c,m,n的值
输出：多项式的值
如：
输入：x=1, a=2, b=1, c=0,m=0,n=0
输出：3

*/

#include <iostream>
using namespace std;

int main(){
    int x,a,b,c,m,n;
    cout<<"x=";
    cin>>x;
    cout<<"a=";
    cin>>a;
    cout<<"b=";
    cin>>b;
    cout<<"c=";
    cin>>c;
    cout<<"m=";
    cin>>m;
    cout<<"n=";
    cin>>n;
    int res=0;
    int i=0;
    int temp=1;
    for(i=0;i<m;i++){
        temp*=x;
    }
    res=a*temp;
    temp=1;
    for(i=0;i<n;i++){
        temp*=x;
    }
    res+=b*temp;
    res+=c;
    cout<<res<<endl;
    return 0;
}