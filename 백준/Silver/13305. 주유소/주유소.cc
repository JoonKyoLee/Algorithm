#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> dist(N - 1);
    vector<long long> price(N);

    for (int i = 0; i < N - 1; i++) {
        cin >> dist[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> price[i];
    }

    long long answer = 0;
    long long minPrice = price[0];

    for (int i = 0; i < N - 1; i++) {
        minPrice = min(minPrice, price[i]);
        answer += minPrice * dist[i];
    }

    cout << answer << "\n";

    return 0;
}
