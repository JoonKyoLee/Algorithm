#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    unordered_map<string, unordered_set<string>> reported_by;
    unordered_map<string, int> mail_count;

    // 신고 정보 저장
    for (string r : report) {
        stringstream ss(r);

        string from, to;
        ss >> from >> to;

        reported_by[to].insert(from);
    }

    // 정지된 유저 찾기
    for (auto item : reported_by) {
        if (item.second.size() >= k) {
            for (string user : item.second) {
                mail_count[user]++;
            }
        }
    }

    vector<int> answer;

    // 결과 저장
    for (string id : id_list) {
        answer.push_back(mail_count[id]);
    }

    return answer;
}
