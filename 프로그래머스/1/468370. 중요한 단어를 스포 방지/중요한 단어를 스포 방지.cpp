#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct WordInfo {
    int openTime;
    int start;
    string word;
};

int solution(string message, vector<vector<int>> spoiler_ranges) {
    vector<pair<int, int>> words;

    for (int i = 0; i < message.size(); ) {
        if (message[i] == ' ') {
            i++;
            continue;
        }

        int start = i;

        while (i < message.size() && message[i] != ' ') {
            i++;
        }

        int end = i - 1;
        words.push_back({start, end});
    }

    unordered_set<string> normalWords;
    vector<WordInfo> spoilerWords;

    int rangeIndex = 0;

    for (auto [start, end] : words) {
        while (rangeIndex < spoiler_ranges.size() &&
               spoiler_ranges[rangeIndex][1] < start) {
            rangeIndex++;
        }

        bool isSpoiler = false;
        int openTime = -1;

        int temp = rangeIndex;

        while (temp < spoiler_ranges.size() &&
               spoiler_ranges[temp][0] <= end) {
            isSpoiler = true;
            openTime = temp;
            temp++;
        }

        string word = message.substr(start, end - start + 1);

        if (isSpoiler) {
            spoilerWords.push_back({openTime, start, word});
        } else {
            normalWords.insert(word);
        }
    }

    sort(spoilerWords.begin(), spoilerWords.end(),
         [](const WordInfo& a, const WordInfo& b) {
             if (a.openTime == b.openTime) {
                 return a.start < b.start;
             }
             return a.openTime < b.openTime;
         });

    unordered_set<string> openedSpoilerWords;
    int answer = 0;

    for (auto info : spoilerWords) {
        if (normalWords.find(info.word) == normalWords.end() &&
            openedSpoilerWords.find(info.word) == openedSpoilerWords.end()) {
            answer++;
        }

        openedSpoilerWords.insert(info.word);
    }

    return answer;
}
