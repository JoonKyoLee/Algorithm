import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());
        int count = 0;
        int startIndex = 0;
        int endIndex = N - 1;

        int[] numbers = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            numbers[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(numbers);

        while (startIndex < endIndex) {
            if (numbers[startIndex] + numbers[endIndex] < M) {
                startIndex++;
            } else if (numbers[startIndex] + numbers[endIndex] > M) {
                endIndex--;
            } else {
                count++;
                startIndex++;
                endIndex--;
            }
        }

        bw.write(count + "\n");
        bw.flush();
    }
}
