/**
 * gold5
 * 애너그램(6443)
 * 1. 첫째 줄에 단어의 개수가 주어짐
 * 2. 둘째 줄부터 단어가 주어짐(영단어는 소문자로 이루어짐)
 * 3. 백트래킹으로 가능한 애너그램을 모두 출력함(중복을 제외하기 위해서 prev 변수 설정)
 */

package string;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class P6443 {
    static char[] letter, result;
    static boolean[] visited;
    static int N;
    static int wordLength;
    static StringBuilder sb;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        sb = new StringBuilder();

        for (int i = 0; i < N; i++) {
            letter = br.readLine().toCharArray();
            wordLength = letter.length;
            visited = new boolean[wordLength];
            result = new char[wordLength];

            Arrays.sort(letter);

            backtracking(0);
        }

        System.out.println(sb.toString());
    }

    static void backtracking(int depth) {
        if (depth == wordLength) {
            sb.append(result);
            sb.append("\n");
            return;
        }

        char prev = 0; // 예시) AAB, ABA 이후에 AAB가 다시 나오지 않도록 설정
        for (int i = 0; i < wordLength; i++) {
            if (visited[i]) continue;
            if (prev >= letter[i]) continue;

            prev = letter[i];

            visited[i] = true;
            result[depth] = letter[i];
            backtracking(depth + 1);
            visited[i] = false;
        }
    }
}
