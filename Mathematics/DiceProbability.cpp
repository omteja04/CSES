/**
 * Author: omteja04
 * Created on: 10-03-2025 17:41:58
 * Problem: DiceProbability
 * Link: https://cses.fi/problemset/task/1725/
 **/

#include <bits/stdc++.h>
#include <ios>
using namespace std;
using ll = long long;
#define fast_cin()                         \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL);                    \
    std::cout.tie(NULL)
using ld = long double;
void levi() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<ld>> dp(n + 1, vector<ld>(6 * n + 1, 0));
    dp[0][0] = 1.0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 6 * n; j++) {
            for(int k = 1; k <= 6; k++) {
                if(j - k >= 0) {
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
            dp[i][j] /= 6;
        }
    }
    ld ans = 0.0;
    for(int i = a; i <= b; i++) {
        ans += dp[n][i];
    }
    cout << fixed << setprecision(6) << ans;
}

int main() {
    fast_cin();
    levi();
    cout << '\n';
    return 0;
}
