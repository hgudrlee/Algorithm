#include <iostream>

using namespace std;

int main() {
    int max = 0, index = 0;
    int arr[9];

    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 9; i++) {
        if (i == 0) {
            max = arr[i];
        }
        else if (arr[i] > max) {
            max = arr[i];
            index = i;
        }
    }

    cout << max << endl;
    cout << index + 1 << endl;

    return 0;
}