#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second != b.second) {
        return a.second > b.second;
    }
    if (a.first.length() != b.first.length()) {
        return a.first.length() > b.first.length();
    }
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, int> words;
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s.length() < M) {
            continue;
        }
        words[s]++;
    }

    vector <pair<string, int>> v(words.begin(), words.end());
    sort(v.begin(), v.end(), cmp);

    for (auto it : v) {
        cout << it.first << "\n";
    }
    return 0;
}
