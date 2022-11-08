#include <iostream>
#include <malloc.h>

using namespace std;

int main() {
    int num;
    int count, sum;
    int *result;
    char c;

    cin >> num;
    getchar();
    result = (int *)malloc(sizeof(int) * num);
    
    for (int i = 0; i < num; i++) {
        count = 0, sum = 0;
        while(true) {
            scanf("%c", &c);
            if (c == '\n') break;
            else if (c == 'O') count++;
            else if (c == 'X') count = 0;
            sum += count;
        }
        result[i] = sum;
    }

    for (int i = 0; i < num; i++) {
        cout << result[i] << endl;
    }

    return 0;
}