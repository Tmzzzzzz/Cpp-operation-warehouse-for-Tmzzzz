/*
七、设计一个函数，把输入的2进制数转化为10进制数输出。如输入为101，则输出为5。
*/

#include <iostream>
using namespace std;

void trans(int &a,int&sum){
    int i=0;
    for(i=0;a>0;i++){
        int temp=a%10;
        if(temp==1){
            sum+=(1<<i);
        }
        a/=10;
    }
}

int main(){
    int a;
    int sum=0;
    cin>>a;
    trans(a,sum);
    cout<<sum<<endl;

    return 0;
}