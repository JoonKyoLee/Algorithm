import java.util.*;

public class Main {
    static int[] memo;
    public static int recur(int n){
        if(n == 1) return 1;
        else if(n == 2) return 2;
        else if(n == 3) return 4;
        else memo[n] = recur(n - 3) + recur(n - 2) + recur(n - 1);

        return memo[n];
    }

    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int T = input.nextInt();
        memo = new int[11];
        int result[] = new int[T];

        for(int i = 0; i < T; i++){
            int n = input.nextInt();
            result[i] = recur(n);
        }

        for(int i = 0; i < T; i++){
            System.out.println(result[i]);
        }
    }
}