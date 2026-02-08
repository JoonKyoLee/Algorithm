#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int num1, den1, num2, den2;
    cin >> num1 >> den1 >> num2 >> den2;

    int result_num, result_den;
    result_num = num1 * den2 + num2 * den1;
    result_den = den1 * den2;

    int num = gcd(result_num, result_den);
    cout << result_num / num << " " << result_den / num;

    return 0;
}
