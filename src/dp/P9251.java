/**
 * gold5
 * LCS(9251)
 * 1. 두 문자열을 입력받음
 * 2. 주어진 두 문자열의 LCS의 길이를 출력
 */

package dp;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class P9251 {
    static int[][] commonLength;

    public static int lcs(String first, String second) {
        for (int i = 0; i < first.length(); i++) {
            for (int j = 0; j < second.length(); j++) {
                commonLength[i + 1][j + 1] = Math.max(commonLength[i][j + 1], commonLength[i + 1][j]);

                if(first.charAt(i) == second.charAt(j)) {
                    commonLength[i + 1][j + 1] = Math.max(commonLength[i + 1][j + 1], commonLength[i][j] + 1);
                }
            }
        }

        return commonLength[first.length()][second.length()];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String first = br.readLine();
        String second = br.readLine();

        commonLength = new int[first.length() + 1][second.length() + 1];

        bw.write(lcs(first, second) + "\n");
        bw.flush();
    }
}
