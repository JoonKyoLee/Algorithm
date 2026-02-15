#include <bits/stdc++.h>
using namespace std;
map<string, double> mp;
int main() {
    string s;
    int total = 0;
    while (getline(cin, s)) {
        mp[s]++;
        total++;
    }
    cout << fixed;
    cout.precision(4);
    for (auto it : mp) {
        cout << (it).first << " " << (it).second / total * 100 << "\n";
    }
    return 0;
}
