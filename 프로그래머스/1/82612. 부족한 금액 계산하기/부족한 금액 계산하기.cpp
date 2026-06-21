#include <string>
#include <vector>

using namespace std;

long long solution(int price, int money, int count) {
    long long total = 0;

    for (int i = 1; i <= count; i++) {
        total += (long long)price * i;
    }

    if (total <= money) {
        return 0;
    }

    return total - money;
}
