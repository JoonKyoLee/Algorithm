import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine());
        List<Integer> nums = new ArrayList<>();

        for(int i = 0; i < N; i++){
            nums.add(Integer.parseInt(br.readLine()));
        }

        Collections.sort(nums);
        for(int value : nums) {
            sb.append(value).append('\n');
        }

        bw.write(sb.toString());

        bw.flush();
    }
}
