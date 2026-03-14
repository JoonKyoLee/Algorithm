#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> order;
int cnt = 0;

void dfs(int R) {
    visited[R] = true;
    order[R] = ++cnt;

    for (int next : graph[R]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    int N, M, R;
    int u, v;

    cin >> N >> M >> R;

    graph.resize(N + 1);
    visited.resize(N + 1);
    order.resize(N + 1);

    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    }

    dfs(R);

    for (int i = 1; i <= N; i++) {
        cout << order[i] << "\n";
    }
    return 0;
}
