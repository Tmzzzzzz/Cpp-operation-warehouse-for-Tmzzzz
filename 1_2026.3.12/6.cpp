/*
六、设计一个函数，实现指数运算。如输入 2和3，则该函数输出8。
要求：输入参数均为整数。
*/

#include <iostream>
using namespace std;

void index(int &a,int &b){
    int i=1;
    int ini=a;
    if(b==0){
        a=1;
    }
    else{
        for(i=1;i<b;i++){
            a*=ini;
        }
    }
}

int main(){
    int a;
    int b;
    cin>>a>>b;
    index(a,b);
    cout<<a<<endl;
    return 0;
}