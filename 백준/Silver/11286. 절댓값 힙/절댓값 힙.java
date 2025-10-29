import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> pq = new PriorityQueue<>(
                (o1, o2) -> {
                    if (Math.abs(o1) == Math.abs(o2)) {
                        return o1 > o2 ? 1 : -1;
                    } else {
                        return Math.abs(o1) - Math.abs(o2);
                    }
                }
        );

        for (int i = 0; i < N; i++) {
            int number = Integer.parseInt(br.readLine());

            if (number != 0) {
                pq.add(number);
            } else {
                if (pq.isEmpty()) {
                    bw.write(0 + "\n");
                } else {
                    bw.write(pq.poll() + "\n");
                }
            }
        }

        bw.flush();
    }
}