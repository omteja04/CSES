/**
 * Author: omteja04
 * Created on: 02-07-2024 12:17:33
 * Description: Dice_Combinations
 **/

#include <bits/stdc++.h>
#define boo cout << "Boo" << '\n'
using namespace std;
typedef long long ll;
#define cinArr(n, arr)         \
    for (ll i = 0; i < n; i++) \
    cin >> arr[i]
#define coutArr(n, arr)        \
    for (ll i = 0; i < n; i++) \
    cout << arr[i] << ' '
typedef vector<int> v32;
const int MOD = 1000000007;

ll leviDice(int n, v32 &dp) {
    if (n == 0)
        return 1;
    if (dp[n] != 0)
        return dp[n];
    for (int i = 1; i <= 6; i++) {

        if (n - i >= 0) {
            dp[n] += leviDice(n - i, dp);
            dp[n] %= MOD;
        }
    }
    return dp[n];
}

ll leviDiceTable(int n) {
    v32 dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }
    return dp[n];
}




void levi() {
    int n;
    cin >> n;
    v32 dp(n + 1, 0);
    ll ans = leviDiceTable(n);
    // ll ans = leviDice(n, dp);
    cout << ans;
}

int main() {
    levi();
    return 0;
}