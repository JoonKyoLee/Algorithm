#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;

    int index[26] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};
    int time = 0;

    for (char c : s) {
        time += index[c - 'A'];
    }
    cout << time << "\n";
    return 0;
}
