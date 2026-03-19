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