#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() 
{
    stack<int> s;
    string str;
    int value;
    int num;
    int result;

    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> str;
        if (str == "push") {
            cin >> value;
            s.push(value);
        }
        else {
            if (str == "pop") {
                if (s.empty()) result = -1;
                else {
                    result = s.top();
                    s.pop();
                }
            }
            else if (str == "size") {
                result = s.size();
            }
            else if (str == "empty") {
                if (s.empty()) result = 1;
                else result = 0;
            }
            else if (str == "top") {
                if (s.empty()) result = -1;
                else result = s.top();
            }
            cout << result << endl;
        }
    }

    return 0;
}