#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    unordered_map<char, int> key;
    
    for (string s : keymap) {
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            int count = i + 1;
            
            if (key.find(c) == key.end()) {
                key[c] = count;
            } else {
                key[c] = min(key[c], count);
            }
        }
    }
    
    vector<int> answer;
    
    for (string target : targets) {
        int sum = 0;
        bool possible = true;
        
        for (char c : target) {
            if (key.find(c) == key.end()) {
                possible = false;
                break;
            }
            
            sum += key[c];
        }
        
        if (possible) {
            answer.push_back(sum);
        } else {
            answer.push_back(-1);
        }
    }
    
    return answer;
}
