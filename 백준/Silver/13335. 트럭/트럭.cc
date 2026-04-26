#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w, L;
    cin >> n >> w >> L;

    vector<int> truck(n);
    for (int i = 0; i < n; i++) {
        cin >> truck[i];
    }

    queue<int> bridge;

    for (int i = 0; i < w; i++) {
        bridge.push(0);
    }

    int time = 0;
    int idx = 0;
    int weightSum = 0;

    while (idx < n) {
        time++;

        weightSum -= bridge.front();
        bridge.pop();

        if (weightSum + truck[idx] <= L) {
            bridge.push(truck[idx]);
            weightSum += truck[idx];
            idx++;
        } else {
            bridge.push(0);
        }
    }

    cout << time + w << "\n";

    return 0;
}
