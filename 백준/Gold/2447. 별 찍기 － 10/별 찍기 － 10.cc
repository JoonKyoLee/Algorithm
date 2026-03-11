#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> v;

void solution(int x_start, int x_end, int y_start, int y_end) {
    if (x_start == x_end) {
        return;
    }

    int len = x_end - x_start + 1;
    int div = len / 3;

    for (int i = x_start + div; i < x_start + div * 2; i++) {
        for (int j = y_start + div; j < y_start + div * 2; j++) {
            v[i][j] = ' ';
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) {
                continue;
            }
            solution(x_start + i * div, x_start + (i + 1) * div - 1, y_start + j * div, y_start + (j + 1) * div - 1);
        }
    }
}

int main() {
    int N;
    cin >> N;

    v = vector<vector<char>>(N, vector<char>(N, '*'));

    solution(0, N - 1, 0, N - 1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << v[i][j];
        }
        cout << "\n";
    }
    return 0;
}
