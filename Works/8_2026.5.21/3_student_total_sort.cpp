/*
三、修改第一题实现的程序，使支持统计各位学生的总分，
并在原文件中增加一列“总分”，并把学生按“总分”从大到小重排列后输出
（不更改文件内数据的排列顺序）
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class Student {
public:
    string name;
    double english, physics, math, chemistry;
    double total() const {
        return english + physics + math + chemistry;
    }
    void print() const {
        cout << name << "\t" << english << "\t" << physics 
             << "\t" << math << "\t" << chemistry << "\t" << total() << endl;
    }
};

class ScoreManager {
private:
    vector<Student> students;
    string filename;
public:
    void load(const string& fn) {
        filename = fn;
        ifstream file(filename);
        if (!file.is_open()) {
            // 文件不存在，创建新文件并写入表头
            ofstream newFile(filename);
            newFile << "姓名\t英语\t物理\t高数\t化学" << endl;
            newFile.close();
            cout << "文件不存在，已创建新文件！" << endl;
            return;
        }
        string line;
        getline(file, line);  // 跳过表头
        while (getline(file, line)) {
            istringstream iss(line);
            Student s;
            iss >> s.name >> s.english >> s.physics >> s.math >> s.chemistry;
            students.push_back(s);
        }
        file.close();
    }
    void query(const string& name) const {
        for (const auto& s : students) {
            if (s.name == name) {
                cout << "姓名\t英语\t物理\t高数\t化学\t总分" << endl;
                s.print();
                return;
            }
        }
        cout << "未找到！" << endl;
    }
    void add() {
        Student s;
        cout << "姓名 英语 物理 高数 化学：";
        cin >> s.name >> s.english >> s.physics >> s.math >> s.chemistry;
        students.push_back(s);
        ofstream file(filename, ios::app);
        file << s.name << " " << s.english << " " << s.physics << " "
             << s.math << " " << s.chemistry << " " << s.total() << endl;
        file.close();
        cout << "添加成功！" << endl;
    }
    void sortAndDisplay() const {
        vector<Student> sortedStudents = students;
        sort(sortedStudents.begin(), sortedStudents.end(), [](const Student& a, const Student& b) {
            return a.total() > b.total();
        });
        cout << "姓名\t英语\t物理\t高数\t化学\t总分" << endl;
        for (const auto& s : sortedStudents) {
            s.print();
        }
    }
};

int main() {
    ScoreManager manager;
    manager.load("scores.txt"); //读取文件

    cout << "1-查询 2-添加 3-统计 请选择：";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "请输入姓名：";
        string name;
        cin >> name;
        manager.query(name);
    } else if (choice == 2) {
        manager.add();
    } else if (choice == 3) {
        manager.sortAndDisplay();
    }
    return 0;
}