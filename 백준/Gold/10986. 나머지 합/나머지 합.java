import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        long[] sum = new long[N];
        long[] count = new long[M];
        long answer = 0;

        st = new StringTokenizer(br.readLine());
        sum[0] = Integer.parseInt(st.nextToken());
        for (int i = 1; i < N; i++) {
            sum[i] = sum[i - 1] + Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < N; i++) {
            int remainder = (int) (sum[i] % M);

            if (remainder == 0) answer++;

            count[remainder]++;
        }

        for (int i = 0; i < M; i++) {
            if (count[i] > 1) {
                answer = answer + (count[i] * (count[i] - 1) / 2);
            }
        }

        bw.write(answer + "\n");
        bw.flush();
    }
}
