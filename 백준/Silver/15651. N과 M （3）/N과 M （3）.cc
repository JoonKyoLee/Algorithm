#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> nums;
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
        current.push_back(nums[i]);
        find(depth + 1);
        current.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        nums.push_back(i);
    }

    find(0);
    return 0;
}
