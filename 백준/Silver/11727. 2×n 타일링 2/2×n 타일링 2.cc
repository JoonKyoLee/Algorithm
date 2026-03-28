#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> dp(n + 1);
    dp[1] = 1;
    if (n >= 2)
        dp[2] = 3;

    for (int i = 3; i <= n; i++) {
        dp[i] = ((dp[i - 2] * 2) % 10007 + dp[i - 1] % 10007) % 10007;
    }

    cout << dp[n] << "\n";
}
