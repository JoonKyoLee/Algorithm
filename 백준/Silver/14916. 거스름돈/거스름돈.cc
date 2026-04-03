#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int answer = -1;

    for (int five = n / 5; five >= 0; five--) {
        int remain = n - five * 5;
        if (remain % 2 == 0) {
            answer = five + remain / 2;
            break;
        }
    }

    cout << answer << "\n";
}
