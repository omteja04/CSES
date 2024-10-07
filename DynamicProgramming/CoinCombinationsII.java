
/**
 * Author: omteja04
 * Description: Coin_Combinations_II
 */
import java.util.Scanner;

public class CoinCombinationsII {
    public static int MOD = 1000000007;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = sc.nextInt();
        int[] dp = new int[x + 1];
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            int val = sc.nextInt();
            for (int j = val; j <= x; j++) {
                dp[j] += dp[j - val];
                dp[j] %= MOD;
            }
        }
        sc.close();
        System.out.println(dp[x]);
    }

}