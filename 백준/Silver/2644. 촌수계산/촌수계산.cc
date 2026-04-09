#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> relationships;
vector<int> dist;

void bfs(int start) {
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : relationships[curr]) {
            if (dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    relationships.resize(n + 1);
    dist.resize(n + 1, -1);

    int target1, target2;
    cin >> target1 >> target2;

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        relationships[x].push_back(y);
        relationships[y].push_back(x);
    }

    bfs(target1);

    cout << dist[target2] << "\n";
}
