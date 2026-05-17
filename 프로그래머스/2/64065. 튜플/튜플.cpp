#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_set>

using namespace std;

vector<int> solution(string s) {
    vector<string> groups;

    s = s.substr(2, s.size() - 4);

    string temp = "";

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '}' && s[i + 1] == ',' && s[i + 2] == '{') {
            groups.push_back(temp);
            temp = "";
            i += 2;
        } else {
            temp += s[i];
        }
    }

    groups.push_back(temp);

    sort(groups.begin(), groups.end(), [](string a, string b) {
        return a.size() < b.size();
    });
    
    vector<int> answer;
    unordered_set<int> used;
    
    for (string group : groups) {
        stringstream ss(group);
        string num;
        
        while (getline(ss, num, ',')) {
            int value = stoi(num);
            
            if (used.find(value) == used.end()) {
                used.insert(value);
                answer.push_back(value);
            }
        }
    }
    
    return answer;
}
