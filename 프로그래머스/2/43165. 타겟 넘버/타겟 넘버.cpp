#include <string>
#include <vector>

using namespace std;

int result = 0;

void dfs(const vector<int>& numbers, int depth, int target, int sum) {
    if (depth == numbers.size()) {
        if (sum == target) {
            result++;
        }
        return;
    }

    dfs(numbers, depth + 1, target, sum + numbers[depth]);
    dfs(numbers, depth + 1, target, sum - numbers[depth]);
}

int solution(vector<int> numbers, int target) {
    result = 0;
    dfs(numbers, 0, target, 0);
    return result;
}
