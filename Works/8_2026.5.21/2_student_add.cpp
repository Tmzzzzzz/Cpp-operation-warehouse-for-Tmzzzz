/*
二、修改上题实现的程序，使支持从键盘输入新的学生及其各科成绩，并写入文件保存。
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Student {
public:
    string name;
    double english, physics, math, chemistry;
    void print() const {
        cout << name << "\t" << english << "\t" << physics 
             << "\t" << math << "\t" << chemistry << endl;
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
                cout << "姓名\t英语\t物理\t高数\t化学" << endl;
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
             << s.math << " " << s.chemistry << endl;
        file.close();
        cout << "添加成功！" << endl;
    }
};

int main() {
    ScoreManager manager;
    manager.load("scores.txt"); //读取文件

    cout << "1-查询 2-添加 请选择：";
    int choice;
    cin >> choice;
    
    if (choice == 1) {
        cout << "请输入姓名：";
        string name;
        cin >> name;
        manager.query(name);
    } else if (choice == 2) {
        manager.add();
    }
    return 0;
}