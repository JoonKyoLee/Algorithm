#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

vector<vector<int>> mp;
vector<vector<bool>> visited;

vector<int> dx{1, 0, -1, 0};
vector<int> dy{0, 1, 0, -1};

void bfs(Point start) {
    queue<Point> q;
    visited[start.x][start.y] = true;
    q.push(start);

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int x = curr.x + dx[i];
            int y = curr.y + dy[i];

            if (x < 1 || x >= mp.size() || y < 1 || y >= mp[1].size()) {
                continue;
            }

            if (!visited[x][y]) {
                visited[x][y] = true;
                q.push({x, y});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    mp.resize(N + 1);
    visited.resize(N + 1);

    int maxHeight = 0;

    for (int i = 1; i <= N; i++) {
        mp[i].resize(N + 1, 0);
        visited[i].resize(N + 1, false);

        for (int j = 1; j <= N; j++) {
            cin >> mp[i][j];
            maxHeight = max(maxHeight, mp[i][j]);
        }
    }

    int answer = 0;

    for (int h = 0; h <= maxHeight; h++) {
        // visited 초기화
        for (int i = 1; i <= N; i++) {
            fill(visited[i].begin(), visited[i].end(), false);
        }

        // 잠긴 곳 체크
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (mp[i][j] <= h) {
                    visited[i][j] = true;
                }
            }
        }

        int area = 0;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (!visited[i][j]) {
                    area++;
                    bfs({i, j});
                }
            }
        }

        answer = max(answer, area);
    }

    cout << answer << "\n";
}
