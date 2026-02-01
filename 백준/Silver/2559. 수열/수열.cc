#include <bits/stdc++.h>
using namespace std;
int n, k, num;
vector<int> temperature;

int main() {
    cin >> n >> k;
    cin >> num;
    temperature.push_back(num);
    for (int i = 1; i < n; i++) {
        cin >> num;
        temperature.push_back(num + temperature[i - 1]);
    }

    int result = temperature[k - 1];
    for (int i = k; i < n; i++) {
        int temp = temperature[i] - temperature[i - k];
        if (result < temp) {
            result = temp;
        }
    }

    cout << result << "\n";
}