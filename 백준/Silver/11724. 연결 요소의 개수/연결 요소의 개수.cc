#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int>> mp;

void bfs(int point) {
    queue<int> q;
    visited[point] = true;
    q.push(point);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : mp[curr]) {
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

    int N, M;
    cin >> N >> M;

    mp.resize(N + 1);
    visited.resize(N + 1, false);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }

    int area = 0;
    
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            ++area;
            bfs(i);
        }
    }

    cout << area << "\n";
}
