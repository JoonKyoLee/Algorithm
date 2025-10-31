import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[][] partSum = new int[N + 1][N + 1];

        for (int i = 0; i < N + 1; i++) {
            partSum[0][i] = 0;
            partSum[i][0] = 0;
        }

        for (int i = 1; i < N + 1; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j = 1; j < N + 1; j++) {
                partSum[i][j] = partSum[i - 1][j] + partSum[i][j - 1] - partSum[i - 1][j - 1] + Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int firstX = Integer.parseInt(st.nextToken());
            int firstY = Integer.parseInt(st.nextToken());
            int secondX = Integer.parseInt(st.nextToken());
            int secondY = Integer.parseInt(st.nextToken());

            bw.write((partSum[secondX][secondY] - partSum[firstX - 1][secondY] - partSum[secondX][firstY - 1] + partSum[firstX - 1][firstY - 1]) + "\n");
        }

        bw.flush();
    }
}