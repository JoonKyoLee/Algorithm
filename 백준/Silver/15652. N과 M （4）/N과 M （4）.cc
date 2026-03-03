#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> numbers;
vector<int> current;

void find(int depth) {
    if (depth == M) {
        for (int x : current) {
            cout << x << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        if (depth != 0) {
            if (current[depth - 1] <= numbers[i]) {
                current.push_back(numbers[i]);
            } else {
                continue;
            }
        } else {
            current.push_back(numbers[i]);
        }
        find(depth + 1);
        current.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        numbers.push_back(i);
    }

    find(0);
    return 0;
}
