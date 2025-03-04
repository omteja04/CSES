/**
 * Author: omteja04
 * Created on: 27-02-2025 17:16:04
 * Problem: DistributingApples
 * Link: https://cses.fi/problemset/task/1716
 **/

#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
#define fast_cin()                         \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL);                    \
    std::cout.tie(NULL)
const int MAX = 2e6;
vector<ll> fact(MAX, 1), inverseFact(MAX, 1);
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
void initialize() {
    for(int i = 2; i < MAX; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inverseFact[MAX - 1] = binPow(fact[MAX - 1], MOD - 2, MOD);
    for(int i = MAX - 2; i > 0; i--) {
        inverseFact[i] = inverseFact[i + 1] * (i + 1) % MOD;
    }
}

ll C(ll n, ll r) {
    return fact[n] * inverseFact[r] % MOD * inverseFact[n - r] % MOD;
}
void levi() {
    ll n, r;
    cin >> n >> r;
    //  Here The containers are the children so `n = k`
    cout << C(n + r - 1, n - 1);
}

int main() {
    fast_cin();
    initialize();
    levi();
    cout << '\n';
    return 0;
}
