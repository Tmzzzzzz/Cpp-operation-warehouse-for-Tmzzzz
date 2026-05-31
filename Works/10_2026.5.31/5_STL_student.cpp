/*
五、学生成绩管理系统
设计一个简易成绩管理系统，根据场景选择最合适的容器：
1.	定义结构体Student，包含：学号 (int)、姓名 (string)、成绩 (double)
2.	使用vector存储所有学生信息（支持随机查询）
实现功能： 
1.	添加5名学生信息
2.	按成绩降序排序学生列表
3.	使用deque缓存成绩前 3 名的学生（代表频繁取头部元素）
4.	使用list存储不及格（<60 分）的学生（代表频繁删除）
5.	分别打印：全部学生、前三名学生、不及格学生

*/

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

using namespace std;

struct Student {
    int id;
    string name;
    double score;
};

int main(){
    vector<Student> students = {
        {1, "Alice", 85.5},
        {2, "Bob", 92.0},
        {3, "Charlie", 78.0},
        {4, "David", 55.0},
        {5, "Eve", 68.0}
    };

    // 按成绩降序排序
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.score > b.score;
    });

    // 使用deque缓存成绩前3名的学生
    deque<Student> topStudents(students.begin(), students.begin() + 3);

    // 使用list存储不及格的学生
    list<Student> failingStudents;
    for (const auto& student : students) {
        if (student.score < 60) {
            failingStudents.push_back(student);
        }
    }

    cout << "全部学生:" << endl;
    for (const auto& student : students) {
        cout << student.id << " " << student.name << " " << student.score << endl;
    }

    cout << "\n前三名学生:" << endl;
    for (const auto& student : topStudents) {
        cout << student.id << " " << student.name << " " << student.score << endl;
    }

    cout << "\n不及格学生:" << endl;
    for (const auto& student : failingStudents) {
        cout << student.id << " " << student.name << " " << student.score << endl;
    }

    return 0;
}