#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> dp(N + 1, 0);

    dp[1] = 1;
    if (N >= 2) {
        dp[2] = 1;
    }

    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[N] << "\n";
}
