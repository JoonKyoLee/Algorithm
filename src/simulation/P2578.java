/**
 * silver4
 * 빙고(2578)
 * 1. 첫째 줄부터 다섯째 줄까지 빙고판에 쓰여진 수가 주어짐
 * 2. 나머지 다섯 줄에 사회자가 부르는 수가 주어짐
 * 3. 사회자가 부른 수로 빙고가 3개 이상 되면 사회자가 몇 개의 수를 불렀는지 출력
 */

package simulation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P2578 {

    static int[][] user = new int[5][5];
    static int[] answer = new int[25];
    static int[][] bingo = new int[5][5];
    static int bingoCount = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        for (int i = 0; i < 5; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j = 0; j < 5; j++) {
                user[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int answerIndex = 0;
        for (int i = 0; i < 5; i++) {
            st = new StringTokenizer(br.readLine());

            while (st.hasMoreTokens()) {
                answer[answerIndex++] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    if (answer[i] == user[j][k]) {
                        bingo[j][k] = 1;
                    }
                }
            }

            rCheck();
            cCheck();
            lrCheck();
            rlCheck();

            if (bingoCount >= 3) {
                System.out.println(i + 1);
                break;
            }
            bingoCount = 0;
        }
    }

    static void rCheck() {
        for (int i = 0; i < 5; i++) {
            int visitedCount = 0;
            for (int j = 0; j < 5; j++) {
                if (bingo[i][j] == 1) {
                    visitedCount++;
                }
            }
            if (visitedCount == 5) {
                bingoCount++;
            }
        }
    }

    static void cCheck() {
        for (int i = 0; i < 5; i++) {
            int visitedCount = 0;
            for (int j = 0; j < 5; j++) {
                if (bingo[j][i] == 1) {
                    visitedCount++;
                }
            }
            if (visitedCount == 5) {
                bingoCount++;
            }
        }
    }

    static void lrCheck() {
        int visitedCount = 0;
        for (int i = 0; i < 5; i++) {
            if (bingo[i][i] == 1) {
                visitedCount++;
            }
        }
        if (visitedCount == 5) {
            bingoCount++;
        }
    }

    static void rlCheck() {
        int visitedCount = 0;
        for (int i = 0; i < 5; i++) {
            if (bingo[i][4 - i] == 1) {
                visitedCount++;
            }
        }
        if (visitedCount == 5) {
            bingoCount++;
        }
    }
}
