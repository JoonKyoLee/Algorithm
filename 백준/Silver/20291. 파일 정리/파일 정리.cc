#include <bits/stdc++.h> // 66 page, 123 -> map
using namespace std;
map<string, int> mp;
int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        s = s.substr(s.find(".") + 1);
        mp[s] += 1;
    }

    for (auto it : mp) {
        cout << (it).first << " " << (it).second << "\n";
    }
    return 0;
}
