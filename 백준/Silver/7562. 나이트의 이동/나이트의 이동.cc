#include <bits/stdc++.h>
using namespace std;

struct Status {
    int x, y;
};

vector<int> dx{-2, -2, -1, -1, 1, 1, 2, 2};
vector<int> dy{1, -1, 2, -2, 2, -2, 1, -1};

int bfs(int l, Status start, Status target) {
    vector<vector<int>> dist(l, vector<int>(l, -1));
    queue<Status> q;
    q.push(start);
    dist[start.x][start.y] = 0;

    while (!q.empty()) {
        Status curr = q.front();
        q.pop();

        if (curr.x == target.x && curr.y == target.y) {
            return dist[curr.x][curr.y];
        }

        for (int i = 0; i < 8; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (0 > nx || nx >= l || 0 > ny || ny >= l) {
                continue;
            }

            if (dist[nx][ny] == -1) {
                dist[nx][ny] = dist[curr.x][curr.y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int l;
        cin >> l;

        int start_x, start_y, end_x, end_y;
        cin >> start_x >> start_y >> end_x >> end_y;

        cout << bfs(l, {start_x, start_y}, {end_x, end_y}) << "\n";
    }

    return 0;
}
