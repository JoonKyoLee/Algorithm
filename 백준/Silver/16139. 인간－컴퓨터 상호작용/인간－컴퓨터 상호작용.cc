#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    int q;
    cin >> S;
    cin >> q;

    vector<vector<int>> v(26, vector<int>(S.length() + 1, 0));

    for (int i = 0; i < 26; i++) {
        for (int j = 1; j < S.length() + 1; j++) {
            if (S[j - 1] == 'a' + i) {
                v[i][j] = v[i][j - 1] + 1;
            }
            else {
                v[i][j] = v[i][j - 1];
            }
        }
    }

    for (int i = 0; i < q; i++) {
        char alphabet;
        int l, r;
        cin >> alphabet >> l >> r;

        cout << v[alphabet - 'a'][r + 1] - v[alphabet - 'a'][l] << "\n";
    }
    return 0;
}
