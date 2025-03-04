/**
 * Author: omteja04
 * Created on: 27-02-2025 17:54:25
 * Problem: DistributingApplesWithoutPreComputation
 * Link: https://cses.fi/problemset/task/1716
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

#define fast_cin()                         \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL);                    \
    std::cout.tie(NULL)

ll binPow(ll x, ll y, ll mod) {
    ll res = 1;
    while(y > 0) {
        if(y & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}

ll C(ll n, ll r) {
    if(r > n) {
        return 0;  // Invalid case
    }
    ll numerator = 1, denominator = 1;

    for(ll i = 0; i < r; i++) {
        numerator = (numerator * (n - i)) % MOD;      // Compute numerator (n * (n-1) * ... * (n-r+1))
        denominator = (denominator * (i + 1)) % MOD;  // Compute denominator (r!)
    }

    return (numerator * binPow(denominator, MOD - 2, MOD)) % MOD;  // Use Fermat's theorem for modular inverse
}

void levi() {
    ll n, r;
    cin >> n >> r;
    cout << C(n + r - 1, n - 1);
}

int main() {
    fast_cin();
    levi();
    cout << '\n';
    return 0;
}
