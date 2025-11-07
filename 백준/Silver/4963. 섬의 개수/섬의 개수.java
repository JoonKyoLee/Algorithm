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

public class Main {

    static int col, row;
    static int[][] land;
    static boolean[][] visited;
    static Stack<Land> lands;
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

            while (!lands.empty()) {
                Land newLand = lands.pop();
                int x = newLand.x;
                int y = newLand.y;

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
        visited[x][y] = true;

        for (int k = 0; k < 8; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;

            if (!visited[nx][ny]) {
                visited[nx][ny] = true;

                if (land[nx][ny] == 1) {
                    dfs (nx, ny);
                }
            }
        }
    }
}
