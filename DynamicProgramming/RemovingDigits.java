/**
 * Removing_Digits
 */
import java.util.*;
public class RemovingDigits {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] dp = new int[n + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int val = i;
            while (val > 0) {
                int digit = val % 10;
                val /= 10;
                if (digit > 0) {
                    dp[i] = Integer.min(dp[i], dp[i - digit] + 1);
                }
            }
        }
        sc.close();
        System.out.println(dp[n]);
    }
}