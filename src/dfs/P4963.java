/**
 * silver2
 * 섬의 개수(4963)
 * 1. 입력은 여러 개의 테스트 케이스로 이루어짐
 * 2. 각 테스트 케이스의 첫째 줄에는 지도의 너비와 높이가 주어짐
 * 3. 둘째 줄부터는 지도가 주어지며 1은 땅, 0은 바다임
 * 4. 입력의 마지막 줄에는 0이 두 개 주어짐
 */

package dfs;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;

class Land {
    int x, y;

    Land (int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class P4963 {

    static int col, row;
    static int[][] land;
    static boolean[][] visited;
    static Stack<Land> lands;
    // 상, 하, 좌, 우, 대각선까지 확인해야 하기 때문에 8개가 필요
    static int[] dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int[] dy = {-1, 0, 1, -1, 1, 0, -1, 1};
    static int landCount;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;


        while (true) {
            st = new StringTokenizer(br.readLine());
            col = Integer.parseInt(st.nextToken());
            row = Integer.parseInt(st.nextToken());

            if (col == 0 && row == 0) break;

            land = new int[row][col];
            visited = new boolean[row][col];
            lands = new Stack<>();
            landCount = 0;

            // 섬과 바다를 이차원 배열로 읽고 섬일 경우에는 stack에 push
            for (int i = 0; i < row; i++)
            {
                st = new StringTokenizer(br.readLine());

                for (int j = 0; j < col; j++) {
                    land[i][j] = Integer.parseInt(st.nextToken());

                    if (land[i][j] == 1) {
                        lands.push(new Land(i, j));
                    }
                }
            }

            // stack에 있는 것들을 모두 확인
            while (!lands.empty()) {
                Land newLand = lands.pop();
                int x = newLand.x;
                int y = newLand.y;

                // 방문한 적이 없는 땅일 경우에는 섬의 개수를 +1 (dfs를 통해서 인접 노드를 모두 확인)
                if (!visited[x][y]) {
                    landCount++;
                    dfs(x, y);
                }
            }

            bw.write(landCount + "\n");
        }

        bw.flush();
    }

    static void dfs(int x, int y) {
        visited[x][y] = true; // 방문 확인

        for (int k = 0; k < 8; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;

            if (!visited[nx][ny]) {
                visited[nx][ny] = true;

                // 섬일 경우에는 연결되어 있는 섬을 찾기 위해 dfs 실행
                if (land[nx][ny] == 1) {
                    dfs (nx, ny);
                }
            }
        }
    }
}
