/**
 * silver2
 * A -> B(16953)
 * 1. 짝수이면 2로 나눔
 * 2. 끝자리가 1이면 10으로 나눔
 * 3. 그 밖의 수일 경우에는 -1 출력
 */

package greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P16953 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int count = 0;

        while (A < B) {
            if (B % 2 == 0) {
                B = B / 2;
                count++;
            } else if (B % 10 == 1) {
                B = B / 10;
                count++;
            } else {
                break;
            }
        }

        if (count == -1 || A != B) {
            System.out.println("-1");
        } else {
            System.out.println(count + 1);
        }
    }
}
