#include <bits/stdc++.h>
using namespace std;

struct House {
    int x, y;
};

vector<vector<int>> mp;
vector<vector<bool>> visited;
vector<House> house;
queue<House> q;
vector<int> part;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(House point) {
    int cnt = 0;
    visited[point.x][point.y] = true;
    q.push(point);

    while(!q.empty()) {
        House house = q.front();
        q.pop();
        ++cnt;

        int m = house.x;
        int n = house.y;

        for (int i = 0; i < 4; i++) {
            int col = m + dx[i];
            int row = n + dy[i];

            if (col < 0 || col >= mp.size() || row < 0 || row >= mp.size()) {
                continue;
            }

            if (mp[col][row] == 1 && !visited[col][row]) {
                visited[col][row] = true;
                q.push({col, row});
            }
        }
    }

    part.push_back(cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    mp.resize(N);
    visited.resize(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        string curr;
        cin >> curr;

        for (int j = 0; j < N; j++) {
            int num = curr[j] - '0';
            mp[i].push_back(num);

            if (num == 1) {
                house.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < house.size(); i++) {
        if (!visited[house[i].x][house[i].y]) {
            bfs(house[i]);
        }
    }

    sort(part.begin(), part.end());
    cout << part.size() << "\n";
    for (int i = 0; i < part.size(); i++) {
        cout << part[i] << "\n";
    }
}
