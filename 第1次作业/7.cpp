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