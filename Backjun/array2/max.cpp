#include <iostream>

using namespace std;

int main() {
    int num[9][9];
    int max = 0;
    int row, col;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> num[i][j];
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (num[i][j] >= max) {
                max = num[i][j];
                row = i + 1;
                col = j + 1;
            }
        }
    }

    cout << max << endl;
    cout << row << " " << col << endl;
    return 0;
}