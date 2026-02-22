// 최종 점수가 같은 경우에는 풀이 제출 횟수가 적은 팀의 순위가 높음
// 최종 점수가 같고 제출 횟수가 같으면 마지막 제출 시간이 더 빠른 팀의 순위가 높음

#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    int n, k, t, m;
    int i, j, s;
    cin >> T;

    struct Team {
        int id;
        int total;
        int submit;
        int last;
    };

    for (int a = 0; a < T; a++) {
        cin >> n >> k >> t >> m;
        vector<vector<int>> score(n, vector<int>(k, 0));
        vector<int> total_score(n);
        vector<int> submit_count(n);
        vector<int> last_submit_time(n);

        for (int b = 0; b < m; b++) {
            cin >> i >> j >> s;
            score[i - 1][j - 1] = max(score[i - 1][j - 1], s);
            submit_count[i - 1]++;
            last_submit_time[i - 1] = b;
        }

        for (int b = 0; b < n; b++) {
            for (int c = 0; c < k; c++) {
                total_score[b] += score[b][c];
            }
        }

        vector<Team> teams;
        for (int b = 0; b < n; b++) {
            teams.push_back({b + 1, total_score[b], submit_count[b], last_submit_time[b]});
        }

        sort(teams.begin(), teams.end(), [](Team &a, Team &b)
             {
            if (a.total != b.total) {
                return a.total > b.total;
            }
            if (a. submit != b. submit) {
                return a.submit < b.submit;
            }
            return a.last < b.last;
        });

        for (int b = 0; b < n; b++) {
            if (teams[b].id == t) {
                cout << b + 1 << "\n";
                break;
            }
        }
    }
    return 0;
}
