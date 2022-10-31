#include <iostream>

using namespace std;

int main() {
    int arr[10];
    int i, j;
    int count = 0;

    for (i = 0; i < 10; i++) {
        cin >> arr[i];
        arr[i] %= 42;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) break;
        }
        if (i == j) {
            count += 1;
        }
    }

    cout << count << endl;
    
    return 0;
}