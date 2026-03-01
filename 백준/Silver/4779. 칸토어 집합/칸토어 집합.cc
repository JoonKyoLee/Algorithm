#include <bits/stdc++.h>
using namespace std;
string s;
void split(int start, int end) {
    if (start >= end) {
        return;
    }
    int div = (end - start + 1) / 3;
    int first = start;
    int second = start + div;
    int third = second + div;
    for (int i = second; i < third; i++) {
        s[i] = ' ';
    }
    split(first, second - 1);
    split(third, end);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N;

    while(cin >> N) {
        int count = (int)pow(3, N);

        s.assign(count, '-');
        split(0, count - 1);
        
        cout << s << "\n";
    }
    return 0;
}
