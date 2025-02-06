/**
 * Author: omteja04
 * Created on: 21-01-2025 23:17:22
 * Description: Book_Shop
 **/

#include <algorithm>
#include <iostream>
#include <vector>
int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> prices(n);
    std::vector<int> pages(n);
    for(int i = 0; i < n; i++) {
        std::cin >> prices[i];
    }
    for(int i = 0; i < n; i++) {
        std::cin >> pages[i];
    }
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(x + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int amount = 0; amount <= x; amount++) {
            dp[i][amount] = dp[i - 1][amount];
            if(amount >= prices[i - 1]) {
                dp[i][amount] = std::max(dp[i][amount], dp[i - 1][amount - prices[i - 1]] + pages[i - 1]);
            }
        }
    }
    std::cout<<dp[n][x];
    // std::vector<int> dp(x + 1, 0);

    // for(int i = 0; i < n; i++) {
    //     for(int amount = x; amount >= prices[i]; amount--) {
    //         dp[amount] = std::max(dp[amount], dp[amount - prices[i]] + pages[i]);
    //     }
    // }
    // std::cout << dp[x];
}
