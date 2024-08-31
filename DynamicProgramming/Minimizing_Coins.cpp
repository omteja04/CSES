/**
 * Author: omteja04
 * Created on: 02-07-2024 17:55:00
 * Description: Minimizing_Coins
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
const int MOD = 1000000007;
typedef vector<int> v32;

int memoization(int n, int k, v32 &arr, v32 &dp) {

    // BASE CASE
    if (k == 0) {
        return 0;
    }
    if (k < 0) {
        return INT_MAX;
    }
    // Memoization
    if (dp[k] != -1) {
        return dp[k];
    }
    int mini = INT_MAX;
    for (int i = 0; i < n; i++) {
        int ans = memoization(n, k - arr[i], arr, dp);
        if (ans != INT_MAX) {
            mini = min(mini, ans + 1);
        }
    }
    return dp[k] = mini;
}
int tabulation(int n, int k, v32 &arr) {
    v32 dp(k + 1, INT_MAX);
    dp[0] = 0;
    for (int amt = 0; amt <= k; amt++) {
        for (int i = 0; i < n; i++) {
            if (amt - arr[i] >= 0 && dp[amt - arr[i]] != INT_MAX) {
                dp[amt] = min(dp[amt], dp[amt - arr[i]] + 1);
            }
        }
    }
    // cout << "HI";
    // cout << (dp[k] == INT_MAX ? -1 : dp[k]);
    return dp[k];
}

void leviCoins(int n, int k, v32 &arr) {
    v32 dp(k + 1, -1);

    // cout << memoization(n, k, arr, dp);
    int ans = tabulation(n, k, arr);
    if (ans == INT_MAX)
        cout << -1;
    else
        cout << ans;
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> arr(n);
    cinArr(n, arr);
    leviCoins(n, k, arr);
    return 0;
}