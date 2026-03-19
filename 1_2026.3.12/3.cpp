/*
三、从键盘输入一个整数，在屏幕打印输出该整数的所有因子。
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int num;
    cin >> num;
    int i;
    for (i = 1; i <= num; i++) {
        if (num%i==0){
            cout << i << " ";
        }
    }
    return 0;
}