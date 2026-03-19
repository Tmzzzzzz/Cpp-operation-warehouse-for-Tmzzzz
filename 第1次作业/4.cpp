#include <iostream>
using namespace std;
int main(){
    int  high , low;
    cin >> high >> low;
    int type=0;
    if (high>=160||low>=100) {
        type=4;
    }
    if (high<=159&&low<=99) {
        type=3;
    }
    if (high<=139&&low<=89) {
        type=2;
    }
    if (high<=120&&low<=80) {
        type=1;
    }

    switch(type){
        case 1:
        cout<<"正常血压"<<endl;
        break;
        case 2:
        cout<<"高血压前期"<<endl;
        break;
        case 3:
        cout<<"1期高血压"<<endl;
        break;
        case 4:
        cout<<"2期高血压"<<endl;
        break;
    }

    return 0;
}