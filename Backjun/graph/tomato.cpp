#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int col, row;
int cnt = 0;
vector<vector<int>> Map;
queue<pair<int, int>> tomato_pos;
int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};

void findCount() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (Map[i][j] == 0) {
                cout << -1 << endl;
                return;
            }
            if (cnt < Map[i][j]) {
				cnt = Map[i][j];
			}
        }
    }
    cout << cnt - 1 << endl;
}

void tomatoBFS() {
    while(!tomato_pos.empty()) {
        int flag = 0;
        pair<int, int> tomato = tomato_pos.front();
        tomato_pos.pop();
        int y_pos = tomato.first;
        int x_pos = tomato.second;
        for (int k = 0; k < 4; k++) {
            int y_dir = y_pos+y[k];
            int x_dir = x_pos+x[k];
            if (y_dir < 0 || x_dir < 0 || y_dir >= row || x_dir >= col) continue;
            if (Map[y_dir][x_dir] == 0) {
                Map[y_dir][x_dir] = Map[y_pos][x_pos] + 1;
                tomato_pos.push(make_pair(y_dir, x_dir));
            }
        }
    }
}

int main() {
    scanf("%d %d", &col, &row);
    Map.resize(row);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int tomato;
            cin >> tomato;
            Map[i].push_back(tomato);
            if (tomato == 1) {
                tomato_pos.push(make_pair(i, j));
            }
        }
    }

    tomatoBFS();
    findCount();
}