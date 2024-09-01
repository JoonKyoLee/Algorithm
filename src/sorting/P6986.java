/**
 * silver3
 * 절사평균(6986)
 * 1. 첫째 줄에 전체 점수의 개수와 제외되는 점수의 개수가 주어짐
 * 2. 절사평균은 정렬된 점수에서 양 끝 K개를 제외하고 평균을 냄
 * 3. 보정평균은 정렬된 점수에서 양쪽 끝에서 K개를 남은 점수 중 가장 가까운 것으로 교체하고 평균을 냄
 */

package sorting;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class P6986 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        double[] numbers = new double[N];
        for (int i = 0; i < N; i++) {
            numbers[i] = Double.parseDouble(br.readLine());
        }

        Arrays.sort(numbers);

        double sum = 0.0;
        for (int i = K; i < N - K; i++) {
            sum += numbers[i];
        }
        System.out.printf("%.2f%n", sum / (N - K * 2) + 1e-8);

        for (int i = 0; i < K; i++) {
            sum += numbers[K];
            sum += numbers[N - K - 1];
        }
        System.out.printf("%.2f%n", sum / N + 1e-8);
    }
}
