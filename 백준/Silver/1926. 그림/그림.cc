#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> paintings;
vector<vector<bool>> visited;
int mx = 0;

struct Point {
    int x, y;
};

vector<int> dx{-1, 1, 0, 0};
vector<int> dy{0, 0, 1, -1};

void bfs(Point start) {
    int range_max = 0;
    queue<Point> q;
    q.push(start);
    visited[start.x][start.y] = true;

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();
        ++range_max;

        for (int i = 0; i < 4; i++) {
            int x = curr.x + dx[i];
            int y = curr.y + dy[i];

            if (x < 0 || x >= paintings.size() || y < 0 || y >= paintings[0].size()) {
                continue;
            }

            if (paintings[x][y] == 1 && !visited[x][y]) {
                visited[x][y] = true;
                q.push({x, y});
            }
        }
    }

    mx = max(mx, range_max);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    paintings.resize(n);
    visited.resize(n);
    for (int i = 0; i < n; i++) {
        paintings[i].resize(m, 0);
        visited[i].resize(m, false);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> paintings[i][j];
        }
    }

    int area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (paintings[i][j] == 1 && !visited[i][j]) {
                ++area;
                bfs({i, j});
            }
        }
    }

    cout << area << "\n";
    cout << mx << "\n";
}
