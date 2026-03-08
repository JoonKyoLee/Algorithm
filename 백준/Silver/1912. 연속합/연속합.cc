#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int current = numbers[0];
    int mx = numbers[0];

    for (int i = 1; i < n; i++) {
        current = max(numbers[i], numbers[i] + current);
        mx = max(mx, current);
    }

    cout << mx << "\n";
    return 0;
}
