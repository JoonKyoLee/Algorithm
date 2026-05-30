#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    unordered_map<char, int> score;

    for (int i = 0; i < survey.size(); i++) {
        char disagree = survey[i][0];
        char agree = survey[i][1];

        int choice = choices[i];

        if (choice < 4) {
            score[disagree] += 4 - choice;
        } else if (choice > 4) {
            score[agree] += choice - 4;
        }
    }

    string answer = "";

    answer += (score['R'] >= score['T']) ? 'R' : 'T';
    answer += (score['C'] >= score['F']) ? 'C' : 'F';
    answer += (score['J'] >= score['M']) ? 'J' : 'M';
    answer += (score['A'] >= score['N']) ? 'A' : 'N';

    return answer;
}
