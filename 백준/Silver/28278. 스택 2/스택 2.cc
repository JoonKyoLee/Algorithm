#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int X, n;
    cin >> X;

    stack<int> stack;

    for (int i = 0; i < X; i++) {
        cin >> n;
        if (n == 1) {
            int number;
            cin >> number;
            stack.push(number);
        } else if (n == 2) {
            if (!stack.empty()) {
                cout << stack.top() << "\n";
                stack.pop();
            } else {
                cout << -1 << "\n";
            }
        } else if (n == 3) {
            cout << stack.size() << "\n";
        } else if (n == 4) {
            if(!stack.empty()) {
                cout << 0 << "\n";
            } else {
                cout << 1 << "\n";
            }
        } else {
            if (!stack.empty()) {
                cout << stack.top() << "\n";
            }
            else {
                cout << -1 << "\n";
            }
        }
    }
    return 0;
}
