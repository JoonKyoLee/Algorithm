#include <string>
#include <vector>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int rows = park.size();
    int cols = park[0].size();
    
    vector<vector<int>> dp(rows + 1, vector(cols + 1, 0));
    
    int maxEmptySize = 0;
    
    for (int r = 1; r <= rows; r++) {
        for (int c = 1; c <= cols; c++) {
            if (park[r - 1][c - 1] == "-1") {
                dp[r][c] = min(min(dp[r - 1][c], dp[r][c - 1]), dp[r - 1][c - 1]) + 1;
                
                maxEmptySize = max(maxEmptySize, dp[r][c]);
            }
        }
    }
    
    int answer = -1;
    
    for (int size : mats) {
        if (size <= maxEmptySize) {
            answer = max(answer, size);
        }
    }
    return answer;
}
