#include <bits/stdc++.h>
using namespace std;

int N;
int mn = INT_MAX;
vector<vector<int>> ablities;
bool selected[21];

void solution(int idx, int cnt) {
    if (cnt == N / 2) {
        int start = 0;
        int link = 0;

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (selected[i] && selected[j]) {
                    start += ablities[i][j] + ablities[j][i];
                }
                else if (!selected[i] && !selected[j]) {
                    link += ablities[i][j] + ablities[j][i];
                }
            }
        }
        mn = min(mn, abs(start - link));
        return;
    }

    for (int i = idx; i < N; i++) {
        selected[i] = true;
        solution(i + 1, cnt + 1);
        selected[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    ablities.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> ablities[i][j];
        }
    }

    selected[0] = true;
    solution(1, 1);

    cout << mn << "\n";
    return 0;
}
