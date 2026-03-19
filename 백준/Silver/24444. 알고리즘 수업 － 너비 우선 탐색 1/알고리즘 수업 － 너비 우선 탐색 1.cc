#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> points;
vector<bool> visited;
vector<int> order;
int cnt = 0;

void bfs(int R) {
    queue<int> q;
    visited[R] = true;
    q.push(R);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        order[curr] = ++cnt;

        for (int next : points[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, R;
    int u, v;

    cin >> N >> M >> R;

    points.resize(N + 1);
    visited.resize(N + 1, false);
    order.resize(N + 1, 0);

    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        points[u].push_back(v);
        points[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(points[i].begin(), points[i].end());
    }

    bfs(R);

    for (int i = 1; i <= N; i++) {
        cout << order[i] << "\n";
    }
    return 0;
}
