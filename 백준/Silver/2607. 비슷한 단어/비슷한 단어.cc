#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int similar = 0;
    string first, other;
    cin >> n;

    vector<int> origin(26);
    cin >> first;
    for (int i = 0; i < first.length(); i++) {
        origin[first[i] - 'A']++;
    }

    for (int i = 0; i < n - 1; i++) {
        cin >> other;

        if (other.length() > first.length() + 1 || other.length() < first.length() - 1) {
            continue;
        }

        vector<int> others(26);
        for (int j = 0; j < other.length(); j++){
            others[other[j] - 'A']++;
        }

        int diff = 0;
        for (int j = 0; j < 26; j++) {
            diff += abs(origin[j] - others[j]);
        }

        if (first.length() == other.length()) {
            if (diff == 0 || diff == 2) {
                similar++;
            }
        } else {
            if (diff == 1) {
                similar++;
            }
        }
    }

    cout << similar << "\n";
    return 0;
}
