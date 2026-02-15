#include <bits/stdc++.h>
using namespace std;

int main() {
    string X;
    int count = 0;
    int k;
    cin >> X;

    while (X.size() != 1) {
        int sum = 0;
        for (int i = 0; i < X.size(); i++) {
            sum += X[i] - '0';
        }
        X = to_string(sum);
        count++;
    }

    cout << count << "\n";
    if (stoi(X) % 3 == 0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
    return 0;
}
