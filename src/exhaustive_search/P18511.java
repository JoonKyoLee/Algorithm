/**
 * silver5
 * 큰 수 구성하기(18511)
 * N보다 작거나 같은 자연수 중에서 집합 K의 원소로만 구성된 가장 큰 수를 출력하는 프로그램
 * 1. 첫째 줄에 N, K의 원소의 개수가 주어짐
 * 2. 둘째 줄에는 각 원소가 주어짐
 */

package exhaustive_search;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class P18511 {
    static int K;
    static int N;
    static int[] numbers;
    static int answer;

    static void dfs(int current) {
        if (current > N) return;
        if (answer < current) answer = current;

        for (int i = K - 1; i > -1; i--) {
            dfs(current * 10 + numbers[i]);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        numbers = new int[K];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < K; i++) {
            numbers[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(numbers);

        dfs(0);

        System.out.println(answer);
    }
}
