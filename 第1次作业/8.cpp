#include <iostream>
using namespace std;

long long c(int n, int m){
    if(m==0) return 1;
    if(n==0) return 0;
    int res=1;
    int i;
    for(i=1;i<=m;i++){
        res=res*(n-m+i)/i;
    }
    return res;
}

int main(){
    int scan;
    double res;
    int total=c(33,6)*16;
    cin>>scan;
    switch(scan){
        case 1:
            res=c(6,6)*c(27,0)*1;
            break;
        case 2:
            res=c(6,6)*c(27,0)*15;
            break;
        case 3:
            res=c(6,5)*c(27,1)*1;
            break;
        case 4:
            res=c(6,4)*c(27,2)*1+c(6,5)*c(27,1)*15;
            break;
        case 5:
            res=c(6,3)*c(27,3)*1+c(6,4)*c(27,2)*15;
            break;
        case 6:
            res=c(6,2)*c(27,4)*1+c(6,1)*c(27,5)*1+c(6,0)*c(27,6)*1;
            break;
    }
    res=res/total;
    cout<<res*100<<"%"<<endl;

    return 0;
}