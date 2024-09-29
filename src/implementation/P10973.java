/**
 * silver3
 * 이전 순열(10973)
 * 1. 첫째 줄에 N이 주어짐
 * 2. 둘째 줄에 순열이 주어짐
 * 3. 이전에 오는 순열을 출력하며, 사전순으로 가장 처음에 오는 순열이 주어졌을 경우에는 -1 출력
 */

package implementation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P10973 {
    static int[] numbers;
    static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        numbers = new int[N];

        for (int i = 0; i < N; i++) {
            numbers[i] = Integer.parseInt(st.nextToken());
        }

        if (!permutation()) {
            System.out.println("-1");
        } else {
            for (int num : numbers) {
                System.out.print(num + " ");
            }
        }
    }

    /**
     * 이전 순열을 만드는 과정
     * 1. 끝에서부터 숫자가 줄어드는지 확인하고, 인덱스를 파악한다
     * 2. 인덱스가 0일 경우(가장 처음에 오는 순열)에는 false 리턴
     * 3. swap해서 정렬
     */
    static boolean permutation() {
        int i = N - 1;
        while (i > 0 && numbers[i - 1] <= numbers[i]) {
            i--;
        }

        if (i == 0) {
            return false;
        }

        int j = N - 1;
        while (numbers[j] >= numbers[i - 1]) {
            j--;
        }

        swap(i - 1, j);

        j = N - 1;
        while (i < j) {
            swap(i, j);
            i++;
            j--;
        }

        return true;
    }

    static void swap(int a, int b) {
        int temp = numbers[a];
        numbers[a] = numbers[b];
        numbers[b] = temp;
    }
}
