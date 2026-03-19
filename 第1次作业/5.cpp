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