#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<vector<int>> E;
vector<int> path;
vector<int> visited;
queue<int> temp;
int seq = 0;

void BFS(int start) {
    visited[start] = 1;
    temp.push(start);
    path[start] = ++seq;
    while (!temp.empty()) {
        int t = temp.front();
        temp.pop();
        for (int i = 0; i < E[t].size(); i++) {
            int v = E[t][i];
            if (!visited[v]) {
                visited[v] = 1;
                temp.push(v);
                path[v] = ++seq;
            }
        }
    }
}

int main() {
    int node_num = 0, edge_num = 0;
    scanf("%d", &node_num);
    scanf("%d", &edge_num);

    E.resize(node_num+1);
    path.resize(node_num+1);
    visited.resize(node_num+1);

    for (int i = 0; i < edge_num; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        E[v1].push_back(v2);
        E[v2].push_back(v1);
    }

    BFS(1);

    printf("%d", seq - 1);

    return 0;
}