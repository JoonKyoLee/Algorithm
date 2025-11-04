import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int count = 1;
        int startIndex = 1;
        int endIndex = 1;
        int sum = 1;

        while (endIndex != N) {
            if (sum == N) {
                count++;
                endIndex++;
                sum += endIndex;
            } else if (sum > N) {
                sum -= startIndex;
                startIndex++;
            } else {
                endIndex++;
                sum += endIndex;
            }
        }

        bw.write(count + "\n");
        bw.flush();
    }
}
