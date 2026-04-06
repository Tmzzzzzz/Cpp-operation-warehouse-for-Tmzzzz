/*
五、输入一个整数，将各位数字反转后输出。例如，输入123，则程序输出321。
*/

#include <iostream>
using namespace std;
int main(){
    int num;
    cin>>num;
    int i,j;
    int cnt=0;
    int save;
    for(i=1;;i++){
        if(num%10==0){
            break;
        }else{
            save=num%10;
            cout<<save;
            num/=10;
        }
    }

    return 0;
}