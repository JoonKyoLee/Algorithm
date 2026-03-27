#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> path;

void bfs(int start, int end) {
    queue<int> q;
    q.push(start);
    parent[start] = -1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == end) {
            break;
        }

        int a = curr + 1;
        int b = curr - 1;
        int c = curr * 2;

        if (0 <= a && a <= 100000 && parent[a] == -2) {
            q.push(a);
            parent[a] = curr;
        }
        if (0 <= b && b <= 100000 && parent[b] == -2) {
            q.push(b);
            parent[b] = curr;
        }
        if (0 <= c && c <= 100000 && parent[c] == -2) {
            q.push(c);
            parent[c] = curr;
        }
    }
}

void find_path(int K) {
    int curr = K;
    while (curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());
}

int main() {
    int N, K;
    cin >> N >> K;

    parent.resize(100001, -2);

    bfs(N, K);
    find_path(K);

    cout << path.size() - 1 << "\n";

    return 0;
}
