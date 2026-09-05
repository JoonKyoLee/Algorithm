#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int h = park.size();
    int w = park[0].size();

    int r = 0;
    int c = 0;

    // 시작 위치 찾기
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (park[i][j] == 'S') {
                r = i;
                c = j;
            }
        }
    }

    for (string route : routes) {
        char dir = route[0];
        int dist = route[2] - '0';

        int dr = 0;
        int dc = 0;

        if (dir == 'N') dr = -1;
        else if (dir == 'S') dr = 1;
        else if (dir == 'W') dc = -1;
        else if (dir == 'E') dc = 1;

        int nr = r;
        int nc = c;
        bool possible = true;

        // 이동 경로 전체 확인
        for (int i = 0; i < dist; i++) {
            nr += dr;
            nc += dc;

            // 공원 밖으로 나가는 경우
            if (nr < 0 || nr >= h || nc < 0 || nc >= w) {
                possible = false;
                break;
            }

            // 장애물을 만나는 경우
            if (park[nr][nc] == 'X') {
                possible = false;
                break;
            }
        }

        // 전체 경로가 가능할 때만 실제 위치 갱신
        if (possible) {
            r = nr;
            c = nc;
        }
    }

    return {r, c};
}
