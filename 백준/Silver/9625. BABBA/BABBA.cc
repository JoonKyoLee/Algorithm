#include <bits/stdc++.h>
using namespace std;

int main() {
    int K;
    cin >> K;

    vector<vector<int>> dp(2);
    for (int i = 0; i < 2; i++) {
        dp[i].resize(K + 1, 0);
    }

    dp[1][1] = 1;
    
    for (int i = 2; i <= K; i++) {
        dp[0][i] = dp[1][i - 1];
        dp[1][i] = dp[0][i - 1] + dp[1][i - 1];
    }

    cout << dp[0][K] << " " << dp[1][K] << "\n";
}
