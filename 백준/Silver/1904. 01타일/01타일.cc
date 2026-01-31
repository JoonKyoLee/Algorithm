#include <bits/stdc++.h>
using namespace std;
vector<int> dp = {0, 1, 2};

int main() {
    int n;
    cin >> n;
    for (int i = 3; i <= n; i++) {
        dp.push_back((dp[i - 2] + dp[i - 1]) % 15746);
    }
    cout << dp[n] << "\n";
}
