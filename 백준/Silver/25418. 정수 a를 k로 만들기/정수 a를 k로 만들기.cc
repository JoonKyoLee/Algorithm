#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, K;
    cin >> A >> K;

    vector<int> dp(K + 1, 0);

    dp[A] = 0;
    for (int i = A + 1; i <= 2 * A - 1; i++) {
        if (i > K) {
            break;
        }
        dp[i] = dp[i - 1] + 1;
    }

    for (int i = 2 * A; i <= K; i++) {
        if (i % 2 == 0) {
            dp[i] = min(dp[i - 1], dp[i / 2]) + 1;
        } else {
            dp[i] = dp[i - 1] + 1;
        }
    }

    cout << dp[K] << "\n";
}
