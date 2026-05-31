/*
四、三种容器的功能对比实现，要求：
分别使用 vector、deque、list 完成同一个任务，对比用法差异：
1.	生成 1~10 的整数序列
2.	实现三个核心操作： 
3.	头部插入元素 0
4.	尾部插入元素 11
5.	删除第 5 个元素

*/

#include <iostream>
#include <vector>
#include <deque>
#include <list>

using namespace std;

int main(){
    vector<int> vec;
    for (int i = 1; i <= 10; ++i) {
        vec.push_back(i);
    }
    vec.insert(vec.begin(), 0);
    vec.push_back(11);
    vec.erase(vec.begin() + 4);

    deque<int> dq;
    for (int i = 1; i <= 10; ++i) {
        dq.push_back(i);
    }
    dq.push_front(0);
    dq.push_back(11);
    dq.erase(dq.begin() + 4);

    list<int> lst;
    for (int i = 1; i <= 10; ++i) {
        lst.push_back(i);
    }
    lst.push_front(0);
    lst.push_back(11);
    auto it = next(lst.begin(), 4);
    lst.erase(it);

    return 0;
}