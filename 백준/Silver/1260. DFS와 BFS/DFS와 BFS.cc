#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> orders;

void dfs(int start) {
    orders.push_back(start);
    visited[start] = true;

    for (int next : graph[start]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        orders.push_back(curr);

        for (int next : graph[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

void print_result() {
    for (int order : orders) {
        cout << order << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, V;
    cin >> N >> M >> V;

    graph.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    visited.resize(N + 1, false);
    dfs(V);
    print_result();

    visited.clear();
    visited.resize(N + 1, false);
    orders.clear();
    bfs(V);
    print_result();

    return 0;
}
