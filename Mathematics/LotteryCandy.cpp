/**
 * Author: omteja04
 * Created on: 06-03-2025 18:47:38
 * Problem: LotteryCandy
 * Link: https://cses.fi/problemset/task/1727/
 **/

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
using ll = long long;
using ld = long double;
#define fast_cin()                         \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL);                    \
    std::cout.tie(NULL)

long double power(long double x, long long y) {
    long double res = 1;
    while(y > 0) {
        if(y % 2 == 1) {
            res = res * x;
        }
        x = x * x;
        y /= 2;
    }
    return res;
}
void levi() {
    ll n, k;
    cin >> n >> k;
    // P(M <= x) => (x / k) ^ n
    // P(M = x) => P(M <= x) - P(M <= (x - 1))
    // P(M = x) = (x / k) ^ n - ((x - 1) / k)^n
    // E[M] = SumOf(xi*P(M = xi)) where xi = {1, 2, 3 ..,k}
    double maxExpectation = 0.0;
    for(int i = 1; i <= k; i++) {
        ld a = 1.0, b = 1.0;
        for(int j = 1; j <= n; j++) {
            a *= ((ld) i / (ld) k);
            b *= ((ld) (i - 1) / k);
        }
        maxExpectation += (a - b) * i;
        // double a = power((double) i / k, n);
        // double b = (i > 1) ? power((double) (i - 1) / k, n) : 0.0;
        // maxExpectation += (a - b) * i;
    }
    cout << fixed << setprecision(6) << maxExpectation << endl;
}
int main() {
    fast_cin();
    levi();
    cout << '\n';
    return 0;
}
