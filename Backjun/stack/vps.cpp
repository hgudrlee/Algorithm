#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    stack<char> ps;
    int num;
    cin >> num;
    cin.ignore();

    for (int i = 0; i < num; i++)
    {
        string str;
        getline(cin, str);

        for (char c : str) {
            if (ps.empty()) ps.push(c);
            else {
                if (ps.top() == '(' && c == ')') ps.pop();
                else ps.push(c);
            }
        }

        if (ps.empty()) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
            while (!ps.empty()) ps.pop();
        }
    }
}