/**
 * gold5
 * 적록색약(10026)
 * 1. 첫째 줄에 배열의 크기가 주어짐
 * 2. 둘째 줄부터 N개 줄에 각각의 색깔이 주어짐
 * 3. 적록색약이 아닌 사람이 봤을 때의 구역의 개수와 적록색약인 사람이 봤을 때의 구역의 수를 출력
 */

package bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

class Zone {
    int x, y;

    Zone (int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class P10026 {

    static int N;
    static char[][] colors;
    static boolean[][] distinguishCount;
    static boolean[][] confuseCount;
    static Queue<Zone> distinguish;
    static Queue<Zone> confuse;
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        colors = new char[N][N];
        distinguishCount = new boolean[N][N];
        confuseCount = new boolean[N][N];

        distinguish = new LinkedList<>();
        confuse = new LinkedList<>();

        int distinguishArea = 0;
        int confuseArea = 0;

        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < N; j++) {
                colors[i][j] = line.charAt(j);
            }
        }


        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!distinguishCount[i][j]) {
                    distinguishBfs(i, j);
                    distinguishArea++;
                }

                if (!confuseCount[i][j]) {
                    confuseBfs(i, j);
                    confuseArea++;
                }
            }
        }

        System.out.println(distinguishArea + " " + confuseArea);
    }

    static void distinguishBfs (int i, int j) {
        distinguish.add(new Zone(i, j));

        while (!distinguish.isEmpty()) {
            Zone zone = distinguish.poll();
            int x = zone.x;
            int y = zone.y;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

                if (!distinguishCount[nx][ny] && colors[nx][ny] == colors[x][y]) {
                    distinguishCount[nx][ny] = true;
                    distinguish.add(new Zone(nx, ny));
                }
            }
        }
    }

    static void confuseBfs (int i, int j) {
        confuse.add(new Zone(i, j));

        while(!confuse.isEmpty()) {
            Zone zone = confuse.poll();
            int x = zone.x;
            int y = zone.y;

            char color = colors[x][y];

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N || confuseCount[nx][ny]) continue;

                if (color == 'R' || color == 'G') {
                    if (colors[nx][ny] == 'R' || colors[nx][ny] == 'G') {
                        confuseCount[nx][ny] = true;
                        confuse.add(new Zone(nx, ny));
                    }
                } else if (colors[nx][ny] == 'B'){
                    confuseCount[nx][ny] = true;
                    confuse.add(new Zone(nx, ny));
                }
            }
        }
    }
}
