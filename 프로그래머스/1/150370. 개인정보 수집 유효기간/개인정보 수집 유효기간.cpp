#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    unordered_map<string, int> term_map;

    // 약관 종류 저장
    for (string term : terms) {
        stringstream ss(term);

        string type;
        int month;

        ss >> type >> month;

        term_map[type] = month;
    }

    // 오늘 날짜를 일 단위로 변환
    int today_year = stoi(today.substr(0, 4));
    int today_month = stoi(today.substr(5, 2));
    int today_day = stoi(today.substr(8, 2));

    int today_total =
        today_year * 12 * 28 +
        today_month * 28 +
        today_day;

    vector<int> answer;

    // 개인정보 확인
    for (int i = 0; i < privacies.size(); i++) {
        stringstream ss(privacies[i]);

        string date, type;
        ss >> date >> type;

        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        int total =
            year * 12 * 28 +
            month * 28 +
            day;

        // 유효기간 더하기
        total += term_map[type] * 28;

        // 오늘 날짜 이상이면 파기 대상
        if (today_total >= total) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}
