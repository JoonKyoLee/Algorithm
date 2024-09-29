/***
 * gold5
 * 합분해(2225)
 * 1. 첫째 줄에 두 정수 N, K가 주어짐
 * 2. 정수 K개를 더해서 N이 되는 경우의 수를 구하는 프로그램 작성
 * 주의할 점) 0부터 N까지를 모두 이용가능하기 때문에 0도 고려해야 함
 * 예시를 작성하다보면 dp[i][j] = dp[i-1][j] + dp[i][j-1]임을 알 수 있음
 * 오버플로우가 발생할 수 있기 때문에 모듈러 연산을 dp 테이블을 채울 때부터 이용
 */

package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P2225 {
    static int[][] sum;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int mod = 1_000_000_000;

        sum = new int[N + 1][K + 1];

        for (int i = 0; i < N + 1; i++) {
            sum[i][0] = 0;
            sum[i][1] = 1;
        }

        for (int i = 0; i < K + 1; i++) {
            sum[0][i] = 1;
        }

        for (int i = 1; i < N + 1; i++) {
            for (int j = 2; j < K + 1; j++) {
                sum[i][j] = (sum[i][j - 1] + sum[i - 1][j]) % mod;
            }
        }

        System.out.println(sum[N][K]);
    }
}
