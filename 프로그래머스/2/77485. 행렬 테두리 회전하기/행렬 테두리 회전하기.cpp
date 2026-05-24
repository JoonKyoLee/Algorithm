#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<vector<int>> board(rows, vector<int>(columns));

    int num = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            board[i][j] = num++;
        }
    }

    vector<int> answer;

    for (auto query : queries) {
        int x1 = query[0] - 1;
        int y1 = query[1] - 1;
        int x2 = query[2] - 1;
        int y2 = query[3] - 1;

        int temp = board[x1][y1];
        int mn = temp;

        // 왼쪽 세로줄 위로 이동
        for (int i = x1; i < x2; i++) {
            board[i][y1] = board[i + 1][y1];
            mn = min(mn, board[i][y1]);
        }

        // 아래쪽 가로줄 왼쪽으로 이동
        for (int j = y1; j < y2; j++) {
            board[x2][j] = board[x2][j + 1];
            mn = min(mn, board[x2][j]);
        }

        // 오른쪽 세로줄 아래로 이동
        for (int i = x2; i > x1; i--) {
            board[i][y2] = board[i - 1][y2];
            mn = min(mn, board[i][y2]);
        }

        // 위쪽 가로줄 오른쪽으로 이동
        for (int j = y2; j > y1 + 1; j--) {
            board[x1][j] = board[x1][j - 1];
            mn = min(mn, board[x1][j]);
        }

        board[x1][y1 + 1] = temp;
        mn = min(mn, temp);

        answer.push_back(mn);
    }

    return answer;
}
