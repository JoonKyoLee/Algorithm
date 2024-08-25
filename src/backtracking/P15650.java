/**
 * silver3
 * N과 M (2)(15650)
 * 1. 자연수 N, M이 주어짐
 * 2. 길이가 M인 수열을 모두 출력해야 하며 증가하는 수열으로 출력해야 함
 */

package backtracking;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class P15650 {
    static int[] numbers;
    static boolean[] visited;
    static StringBuilder sb = new StringBuilder();

    public static void dfs(int N, int M, int depth) {
        if (depth == M) {
            for (int number : numbers) {
                sb.append(number).append(" ");
            }
            sb.append("\n");
            return;
        }

        for (int i = 0; i < N; i++) {
            if (numbers[0] > N - (M - 1)) {
                continue;
            }
            if (!visited[i]) {
                if (depth != 0 && numbers[depth - 1] > (i + 1)) {
                    continue;
                }
                visited[i] = true;
                numbers[depth] = i + 1;
                dfs(N, M, depth + 1);
                visited[i] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        numbers = new int[M];
        visited = new boolean[N];

        dfs(N, M, 0);
        bw.write(sb.toString());
        bw.flush();
    }
}
