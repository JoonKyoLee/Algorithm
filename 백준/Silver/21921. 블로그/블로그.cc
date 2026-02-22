#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, X;
    cin >> N >> X;

    vector<int> visitors(N);
    for (int i = 0; i < N; i++) {
        cin >> visitors[i];
    }

    long long sum = 0;
    for (int i = 0; i < X; i++) {
        sum += visitors[i];
    }

    long long mx = sum;
    int count = 1;

    for (int i = X; i < N; i++) {
        sum += visitors[i];
        sum -= visitors[i - X];

        if (sum > mx) {
            mx = sum;
            count = 1;
        } else if (sum == mx) {
            count++;
        }
    }

    if (mx != 0) {
        cout << mx << "\n" << count << "\n";
    } else {
        cout << "SAD\n";
    }
    return 0;
}
