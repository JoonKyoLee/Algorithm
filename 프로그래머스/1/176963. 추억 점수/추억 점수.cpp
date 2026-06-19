#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name,
                     vector<int> yearning,
                     vector<vector<string>> photo) {

    unordered_map<string, int> score;

    for (int i = 0; i < name.size(); i++) {
        score[name[i]] = yearning[i];
    }

    vector<int> answer;

    for (auto& people : photo) {
        int sum = 0;

        for (auto& person : people) {
            if (score.find(person) != score.end()) {
                sum += score[person];
            }
        }

        answer.push_back(sum);
    }

    return answer;
}
