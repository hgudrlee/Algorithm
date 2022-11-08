#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pool;

int main() {
    int pnum, inum;
    cin >> pnum;
    for (int i = 0; i < pnum; i++) {
        int num;
        cin >> num;
        pool.push_back(num);
    }
    
    sort(pool.begin(), pool.end());
    cin >> inum;
    // binsearch
    for (int i = 0; i < inum; i++) {
        int num;
        scanf("%d", &num);
        printf("%d\n", binary_search(pool.begin(), pool.end(), num));
    }
    return 0;
}