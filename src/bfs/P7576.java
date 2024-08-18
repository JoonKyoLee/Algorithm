/**
 * gold5
 * 토마토(7576)
 * 보관 후 하루가 지나면, 익은 토마토의 왼쪽, 오른쪽, 앞, 뒤의 4개의 토마토가 익게 됨
 * 1. 상자의 크기는 M X N => 가로 칸의 수는 M, 세로 칸의 수는 N
 * 2. 1은 익은 토마토, 0은 익지 않은 토마토, -1은 들어있지 않은 칸을 의미
 * 3. 토마토가 모두 익을 때까지의 최소 날짜를 출력
 *    (저장될 때부터 모두 익어있는 상태일 때는 0, 토마토가 다 익지 못하는 상황일 때는 -1 출력)
 */

package bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Pair {
    int x, y;

    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
public class P7576 {
    static int M, N;
    static int[][] box;
    static int[][] dist;
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};
    static Queue<Pair> Q;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        box = new int[N][M];
        dist = new int[N][M];
        Q = new LinkedList<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            // 토마토의 상태를 입력
            for (int j = 0; j < M; j++) {
                box[i][j] = Integer.parseInt(st.nextToken());

                // 익어있는 상태일 경우에는 큐에 추가
                if (box[i][j] == 1) {
                    Q.offer(new Pair(i, j));
                }

                // 익지 않은 상태의 경우에는 dist[i][j]를 -1로 설정
                if (box[i][j] == 0) {
                    dist[i][j] = -1;
                }
            }
        }

        // bfs
        while (!Q.isEmpty()) {
            Pair current = Q.poll();

            // 좌, 우, 위, 아래 확인
            for (int i = 0; i < 4; i++) {
                int nx = current.x + dx[i];
                int ny = current.y + dy[i];

                // 인덱스를 벗어났을 때는 넘어감
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                    continue;
                }
                // 익어있으면 넘어감
                if (dist[nx][ny] >= 0) {
                    continue;
                }

                // 익을 때까지 필요한 날짜 판단
                dist[nx][ny] = dist[current.x][current.y] + 1;
                Q.offer(new Pair(nx, ny));
            }
        }

        int result = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (dist[i][j] == -1) {
                    System.out.println("-1");
                    return;
                }
                result = Math.max(result, dist[i][j]);
            }
        }
        System.out.println(result);
    }
}
