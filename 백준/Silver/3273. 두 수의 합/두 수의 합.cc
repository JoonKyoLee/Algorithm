#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
    int n, num, target;
    vector<int> v;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    cin >> target;

    int left = 0;
    int right = n - 1;
    int result = 0;

    while (left < right) {
        int sum = v[left] + v[right];

        if (sum > target) {
            right--;
        }
        else if (sum < target) {
            left++;
        }
        else {
            left++;
            result++;
        }
    }

    cout << result << "\n";
    return 0;
}
