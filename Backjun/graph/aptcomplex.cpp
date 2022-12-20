#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> apt_nums;
vector<vector<int>> Map;
vector<vector<int>> Map2;
int cnt = 0;
int apt_num = 1;
int map_size = 0;
int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};

void DFS(int i, int j) {
    Map[i][j] = 0;
    Map2[i][j] = cnt+1;
    for (int k = 0; k < 4; k++) {
        int row = i+y[k];
        int col = j+x[k];
        if (row < 0 || col < 0 || row >= map_size || col >= map_size) continue;
        //cout << "row: " << row << ", col: " << col << endl;
        if (Map[row][col]) {
            apt_num++;
            DFS(row, col);
        }
    }
    return;
}

int main() {
    scanf("%d", &map_size);
    Map.resize(map_size);
    Map2.resize(map_size);

    // init map
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            int house;
            scanf("%1d", &house);
            Map[i].push_back(house);
            Map2[i].push_back(house);
        }
    }

    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            if (Map[i][j]) {
                DFS(i, j);
                apt_nums.push_back(apt_num);
                apt_num = 1;
                cnt++;
            }
            //cout << "i: " << i << ", j: " << j << endl;
        }
    }

    // for (int i = 0; i < map_size; i++) {
    //     for (int j = 0; j < map_size; j++) {
    //         printf("%1d", Map2[i][j]);
    //     }
    //     printf("\n");
    // }

    sort(apt_nums.begin(), apt_nums.end());
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        printf("%d\n", apt_nums[i]);
    }
    
    return 0;
}