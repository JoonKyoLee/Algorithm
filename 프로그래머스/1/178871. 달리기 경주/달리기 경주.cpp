#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> position;

    for (int i = 0; i < players.size(); i++) {
        position[players[i]] = i;
    }

    for (string name : callings) {
        int idx = position[name];

        string front_player = players[idx - 1];

        swap(players[idx], players[idx - 1]);

        position[name] = idx - 1;
        position[front_player] = idx;
    }

    return players;
}
