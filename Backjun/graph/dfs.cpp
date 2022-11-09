#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, R;
vector<int> visited;
vector<int> path;
vector<vector<int>> E;
int seq = 0;

void DFS(int R) {
    visited[R] = 1;
    path[R] = ++seq;
    for (int i = 0; i < E[R].size(); i++) {
        int v = E[R][i];
        if (!visited[v]) DFS(v);
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &R);
    E.resize(N+1);
    visited.resize(N+1);
    path.resize(N+1);

    for (int i = 0; i < M; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        E[v1].push_back(v2);
        E[v2].push_back(v1);
    }
    for(int i = 1; i <= N; i++) sort(E[i].begin(), E[i].end());

    DFS(R);

    for (int i = 1; i < N+1; i++) printf("%d\n", path[i]);

    return 0;
}