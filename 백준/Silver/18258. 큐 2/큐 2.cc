#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    queue<int> q;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        int num;

        cin >> s;

        if (s == "push") {
            cin >> num;
            q.push(num);
        } else if (s == "pop") {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else if (s == "size") {
            cout << q.size() << "\n";
        } else if (s == "empty") {
            if (q.empty()) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if (s == "front") {
            if (q.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << q.front() << "\n";
            }
        } else {
            if (q.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << q.back() << "\n";
            }
        }
    }
}
