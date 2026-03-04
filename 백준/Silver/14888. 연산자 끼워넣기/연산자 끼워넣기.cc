#include <bits/stdc++.h>
using namespace std;

int N, M;
int mx = INT_MIN;
int mn = INT_MAX;
vector<int> numbers;
vector<int> operators;

int calc(int a, int b, int op) {
    if (op == 0) {
        return a + b;
    } 
    if (op == 1) {
        return a - b;
    } 
    if (op == 2) {
        return a * b;
    }
    return a / b;
}

void find(int depth, int curr) {
    if (depth == N) {
        mx = max(mx, curr);
        mn = min(mn, curr);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (operators[i] == 0) {
            continue;
        }
        operators[i]--;
        find(depth + 1, calc(curr, numbers[depth], i));
        operators[i]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    M = N - 1;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    for (int i = 0; i < 4; i++) {
        int num;
        cin >> num;
        operators.push_back(num);
    }

    find(1, numbers[0]);
    cout << mx << "\n";
    cout << mn << "\n";
    return 0;
}
