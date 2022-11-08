#include <iostream>
#include "stdlib.h"

using namespace std;

int main() {
    int num = 0, min = 0, max = 0;
    int *arr;

    cin >> num;
    arr = (int *)malloc(sizeof(int) * num);

    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < num; i++) {
        if (i == 0) {
            min = max = arr[i];
        }
        else if (arr[i] > max) {
            max = arr[i];
        }
        else if (arr[i] < min) {
            min = arr[i];
        }
    }

    cout << min << " " << max;

    return 0;
}