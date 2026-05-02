#include <bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge;
    
    // 다리 초기화
    for (int i = 0; i < bridge_length; i++) {
        bridge.push(0);
    }
    
    int total_time = 0;
    int current_weight = 0;
    int index = 0;

    while (!bridge.empty()) {
        total_time++;
        
        // 다리에서 트럭 나감
        current_weight -= bridge.front();
        bridge.pop();
        
        // 트럭 올릴 수 있는지 확인
        if (index < truck_weights.size()) {
            if (current_weight + truck_weights[index] <= weight) {
                // 트럭 올림
                bridge.push(truck_weights[index]);
                current_weight += truck_weights[index];
                index++;
            } else {
                // 못 올리면 빈칸
                bridge.push(0);
            }
        }
    }

    return total_time;
}
