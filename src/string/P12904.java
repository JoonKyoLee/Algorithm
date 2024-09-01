/**
 * gold5
 * A와 B(12904)
 * 문자열 뒤에 A를 추가하거나 문자열을 뒤집고 B를 추가할 수 있음
 * 1. 첫째 줄에 S가 주어짐(처음 시작하는 문자열)
 * 2. 둘째 줄에 T가 주어짐(목표로 하는 문자열)
 *
 * 풀이방법(그리디)
 * S에서 출발하지 않고 T에서부터 시작함
 * T의 마지막이 A이면 A를 제외하고 다음으로 넘어가서 확인
 * T의 마지막이 B이면 먼저 B를 제외하고 뒤집음
 * S와 T의 길이가 같아질 때까지 실행 후 S와 T(A 또는 B를 제외한 상태)를 비교
 */

package string;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class P12904 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb;
        String S = br.readLine();
        String T = br.readLine();
        int lengthDifference = T.length() - S.length();

        for (int i = 0; i < lengthDifference; i++) {
            if (T.charAt(T.length() - 1) == 'A') {
                T = T.substring(0, T.length() - 1);
            } else {
                T = T.substring(0, T.length() - 1);
                sb = new StringBuilder(T);
                T = sb.reverse().toString();
            }
        }

        if (S.equals(T)) {
            System.out.println("1");
        } else {
            System.out.println("0");
        }
    }
}
