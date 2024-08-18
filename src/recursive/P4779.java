/***
 * silver3
 * 칸토어 집합(4779)
 * 칸토어 집합은 0과 1사이의 실수로 이루어진 집합으로, 구간 [0,1]에서 시작해서 각 구간을 3등분하여 가운데를 반복적으로 제거
 * 1. 3^N개의 -로 이루어진 문자열
 * 2. 문자열을 3등분하고 가운데 문자열을 공백으로 바꿈
 * 3. 모든 선의 길이가 1일 때까지 계속 반복
 */

package recursive;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class P4779 {
    static int N;
    static int firstLength;
    static char[] word;

    static void Cantor(int n, int currentLength) {
        if (currentLength == 1) { // -가 하나만 존재하면 stop
            return;
        }

        int partLength = currentLength / 3; // 3개의 구간으로 나눔

        for (int i = n + partLength; i < n + 2 * partLength; i++) { // 구간 2 값 변경
            word[i] = ' ';
        }

        // 1, 2, 3의 구간 중, 2의 구간은 제외하고 1, 3의 구간만 호출
        Cantor(n, partLength);
        Cantor(n + 2 * partLength, partLength);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String input;

        while ((input = bf.readLine()) != null) {
            N = Integer.parseInt(input);
            firstLength = (int) Math.pow(3, N);
            word = new char[firstLength];
            StringBuilder sb = new StringBuilder();
            Arrays.fill(word, '-'); // 배열을 -로 채움

            Cantor(0, firstLength); // 재귀함수 호출

            for (int i = 0; i < firstLength; i++) { // 재귀함수 호출 후, 결과 출력
                sb.append(word[i]);
            }
            System.out.println(sb);
        }
    }
}
