#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct Process {
    int priority, index;
};

int solution(vector<int> priorities, int location) {
    queue<Process> q;
    
    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
    }
    
    int order = 0;
    
    while (!q.empty()) {
        Process current = q.front();
        q.pop();
        
        bool hasHigher = false;
        
        queue<Process> temp = q;
        
        while (!temp.empty()) {
            if (temp.front().priority > current.priority) {
                hasHigher = true;
                break;
            }
            temp.pop();
        }
        
        if (hasHigher) {
            q.push(current);
        } else {
            order++;
            
            if (current.index == location) {
                return order;
            }
        }
    }
    
    return -1;
}
