/**
 * Author: omteja04
 * Created on: 05-09-2024 20:56:49
 * Description: Coin_Combinations_I
 **/

#include <bits/stdc++.h>
using namespace std;
#define boo cout << "Boo" << '\n'
#define cin1d(n, arr)          \
    for (ll i = 0; i < n; i++) \
    cin >> arr[i]
#define cout1f(n, arr)         \
    for (ll i = 0; i < n; i++) \
    cout << arr[i] << ' '
using ll = long long;
using vi = vector<int>;
const int MOD = 1000000007;

int leviMemo(int n, int x, vi &arr, vi &dp) {
    if (x == 0)
        return 1;
    if (x < 0) {
        return 0;
    }
    if (dp[x] != -1) {
        return dp[x];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += leviMemo(n, x - arr[i], arr, dp);
        ans = ans % MOD;
    }
    return dp[x] = ans;
}

int leviTab(int n, int x, vi &arr) {
    vi dp(x + 1, 0);
    dp[0] = 1;
    for (int amt = 0; amt <= x; amt++) {
        for (int i = 0; i < n; i++) {
            if (amt - arr[i] >= 0) {
                dp[amt] += dp[amt - arr[i]];
                dp[amt] %= MOD;
            }
        }
    }
    return dp[x];
}

void levi() {
    int n, x;
    cin >> n >> x;
    vi dp(x + 1, -1);
    vi arr(n);
    cin1d(n, arr);
    // int res = leviMemo(n, x, arr, dp);
    int res = leviTab(n, x, arr);
    cout << res;
}

int main() {
    levi();
    return 0;
}