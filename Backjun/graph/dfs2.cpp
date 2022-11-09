#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int N, M, R;
vector<int> visited;
vector<int> path;
vector<vector<int>> E;
stack<int> temp;
int seq = 0;

void DFS(int R) {
    temp.push(R);
    while(!temp.empty()) {
        int t = temp.top();
        temp.pop();
        if (visited[t]) continue;
        visited[t] = 1;
        path[t] = ++seq;
        for (int i = 0; i < E[t].size(); i++) {
            int v = E[t][i];
            if (!visited[v]) temp.push(v);
        }
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

    for (int i = 1; i <= N; i++) printf("%d\n", path[i]);

    return 0;
}