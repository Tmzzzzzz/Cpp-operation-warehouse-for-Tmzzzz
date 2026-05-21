/*
四、用户登录是信息系统的常见功能，该功能一般要求用户输入正确的用户名和密码后，才可以进入系统。
假设某系统用文本文件存储用户信息，如下所示，文件中有两列，第一列为用户名，第二列为密码。
请实现一个用户登录系统，在控制台上要求用户输入用户名和密码，
如果所输入的用户名和密码在以下文件中被匹配上，则显示：欢迎您回来，<用户名>！。
否则，提示用户输入错误，要求用户继续输入，直到输入正确为止。
Jack  abc123
Lee  111111
Mike  358742
Tom  01245a

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
using namespace std;

class UserManager {
private:
    map<string, string> users;
public:
    UserManager(const string& filename) {
        ifstream file(filename);
        if(!file.is_open()) {
            ofstream newFile(filename);
            newFile << "Jack  abc123" << endl;
            newFile << "Lee  111111" << endl;
            newFile << "Mike  358742" << endl;
            newFile << "Tom  01245a" << endl;
            newFile.close();
            file.open(filename);
        }
        string line;
        while(getline(file,line)) {
            istringstream iss(line);
            string username,password;
            iss >> username >> password;
            users[username] = password;
        }
        file.close();
    }
    bool login(const string& username, const string& password) const {
        auto it = users.find(username);
        if (it != users.end() && it->second == password) {
            return true;
        }
        return false;
    }
};

int main(){
    UserManager userManager("users.txt");
    string username, password;
    while (true) {
        cout << "请输入用户名: ";
        cin >> username;
        cout << "请输入密码: ";
        cin >> password;

        if (userManager.login(username, password)) {
            cout << "欢迎您回来，" << username << "！" << endl;
            break;
        } else {
            cout << "用户名或密码错误，请重新输入。" << endl;
        }
    }
    return 0;
}