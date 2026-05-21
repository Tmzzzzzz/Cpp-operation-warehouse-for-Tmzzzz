/*
一、	请编写程序实现读取以下文件的内容，并可根据学生姓名，打印输出该生的所有成绩。
姓名 英语   物理    高数   化学
张三  85    75.5     94    82.5
李四  68.5    85     22    75
王五  98    88.5     78.5   89
马六  48.5    87     87    99
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Student {
private:
    string name;
    vector<double> scores;  // 英语、物理、高数、化学

public:
    Student(const string& line) {
        istringstream iss(line);
        iss >> name;
        double score;
        while (iss >> score) {
            scores.push_back(score);
        }
    }

    string getName() const { return name; }

    void print() const {
        cout << name;
        for (double s : scores) {
            cout << "\t" << s;
        }
        cout << endl;
    }
};

class ScoreManager {
private:
    vector<Student> students;
    string header;  // 表头
public:
    bool load(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) return false;
        getline(file, header);  // 读取表头
        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                students.push_back(Student(line));
            }
        }
        file.close();
        return true;
    }
    void query(const string& name) const {
        for (const auto& stu : students) {
            if (stu.getName() == name) {
                cout << header << endl;
                stu.print();
                return;
            }
        }
        cout << "未找到该学生！" << endl;
    }
};

int main() {
    ofstream f("scores.txt");
    f << "姓名\t英语\t物理\t高数\t化学\n张三\t85\t75.5\t94\t82.5\n李四\t68.5\t85\t22\t75\n王五\t98\t88.5\t78.5\t89\n马六\t48.5\t87\t87\t99\n";
    f.close();  //写入该文件

    ScoreManager manager;
    manager.load("scores.txt"); //读取该文件

    string name;
    cout << "请输入学生姓名查询成绩：";
    cin >> name;
    manager.query(name);

    return 0;
}