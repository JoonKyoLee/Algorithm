#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int cnt;
vector<vector<int>> mp;
vector<Point> cabbages;
vector<vector<bool>> visited;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

void bfs(Point point) {
    queue<Point> q;
    ++cnt;
    q.push(point);
    visited[point.x][point.y] = true;

    while (!q.empty()) {
        Point p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            if (p.x + dx[i] < 0 || p.x + dx[i] >= mp.size() || p.y + dy[i] < 0 || p.y + dy[i] >= mp[0].size()) {
                continue;
            }

            if (!visited[p.x + dx[i]][p.y + dy[i]] && mp[p.x + dx[i]][p.y + dy[i]] == 1) {
                q.push({p.x + dx[i], p.y + dy[i]});
                visited[p.x + dx[i]][p.y + dy[i]] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cnt = 0;
        cabbages.clear();

        int M, N, K;
        cin >> M >> N >> K;

        mp = vector<vector<int>>(N, vector<int>(M, 0));
        visited = vector<vector<bool>>(N, vector<bool>(M, false));

        for (int j = 0; j < K; j++) {
            int X, Y;
            cin >> Y >> X;
            mp[X][Y] = 1;

            cabbages.push_back({X, Y});
        }

        for (Point point : cabbages) {
            if (!visited[point.x][point.y]) {
                bfs({point.x, point.y});
            }
        }

        cout << cnt << "\n";
    }
    return 0;
}
