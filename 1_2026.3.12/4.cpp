/*
四、美国的《美国预防、检测、评估与治疗高血压全国联合委员会第七次报告》，将血压水平分为四类：
正常血压    （≤120/80mmHg），
高血压前期　（120—139/80—89mmHg），
1期高血压  （140—159/90—99mmHg），
2期高血压　（≥160/100mmHg）。
从键盘输入两个整数值，分别表示收缩压（高压）、舒张压（低压），程序输出其血压水平分类。
说明：取高压、低压两者中高的作为判断血压水平的依据，如高压121\低压92，则可诊断为1期高血压。

*/

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
        cout<<"����Ѫѹ"<<endl;
        break;
        case 2:
        cout<<"��Ѫѹǰ��"<<endl;
        break;
        case 3:
        cout<<"1�ڸ�Ѫѹ"<<endl;
        break;
        case 4:
        cout<<"2�ڸ�Ѫѹ"<<endl;
        break;
    }

    return 0;
}