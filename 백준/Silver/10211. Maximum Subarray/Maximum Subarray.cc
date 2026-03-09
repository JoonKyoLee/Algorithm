#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, N;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;
        vector<int> numbers(N);

        for (int i = 0; i < N; i++) {
            cin >> numbers[i];
        }

        int current = numbers[0];
        int mx = numbers[0];

        for (int i = 1; i < N; i++) {
            current = max(current + numbers[i], numbers[i]);
            mx = max(mx, current);
        }

        cout << mx << "\n";
    }
    return 0;
}
