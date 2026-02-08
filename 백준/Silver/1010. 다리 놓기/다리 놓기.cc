#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, N, M;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        int combination = 1;
        int K = 1;

        for (int j = M; j > M - N; j--) {
            combination *= j;
            combination /= K++;
        }
        cout << combination << "\n";
    }
    return 0;
}
