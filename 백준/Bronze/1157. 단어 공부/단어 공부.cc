#include <bits/stdc++.h>
using namespace std;
int main() {
    int alphabets[26] = {0};
    string s;
    cin >> s;
    for (char& c : s) {
        c = toupper(c);
        alphabets[c - 'A']++;
    }

    int mx = 0;
    for (int i = 0; i < 26; i++) {
        mx = max(mx, alphabets[i]);
    }

    int max_count = 0;
    char alphabet;
    for (int i = 0; i < 26; i++) {
        if (mx == alphabets[i]) {
            alphabet = 'A' + i;
            max_count++;
        }
    }

    if (max_count > 1) {
        cout << "?" << "\n";
    } else {
        cout << alphabet << "\n";
    }
    return 0;
}
