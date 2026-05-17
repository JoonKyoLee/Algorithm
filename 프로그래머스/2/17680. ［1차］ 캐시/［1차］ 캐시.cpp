#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if (cacheSize == 0) {
        return cities.size() * 5;
    }
    
    deque<string> cache;
    int answer = 0;
    
    for (int i = 0; i < cities.size(); i++) {
        string city = cities[i];
        
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        
        auto it = find(cache.begin(), cache.end(), city);
        
        if (it != cache.end()) {
            cache.erase(it);
            cache.push_back(city);
            answer += 1;
        } else {
            if (cache.size() == cacheSize) {
                cache.pop_front();
            }
            cache.push_back(city);
            answer += 5;
        }
    }
    
    return answer;
}