/**
 * Author: omteja04
 * Created on: 26-02-2025 15:20:29
 * Problem: ChristmasParty
 * Link: https://cses.fi/problemset/task/1717
 **/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
#define fast_cin()                         \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL);                    \
    std::cout.tie(NULL)

// De-arrangements

// D(n) = (n - 1) (D(n - 1) + D(n - 2))

const int N = 1e6;
vector<ll> fact(N + 1), inverseFact(N + 1);

ll binPow(ll x, ll y, ll mod) {
    ll res = 1;
    while(y > 0) {
        if(y & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % MOD;
        y >>= 1;
    }
    return res;
}
void find() {
    fact[0] = 1;
    for(ll i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inverseFact[N] = binPow(fact[N], MOD - 2, MOD);
    for(int i = N - 1; i >= 0; i--) {
        inverseFact[i] = (inverseFact[i + 1] * (i + 1)) % MOD;
    }
}
void levi() {
    ll n;
    cin >> n;
    // vector<ll> D(n + 1, 0);
    // D[0] = 1;
    // D[1] = 0;
    // D[2] = 1;
    // for(ll i = 3; i <= n; i++) {
    //     D[i] = (((i - 1) % MOD) * (D[i - 1] + D[i - 2]) % MOD) % MOD;
    // }
    // cout << D[n];
    ll res = fact[n];
    ll summation = 0;
    for(int i = 2; i <= n; i++) {
        ll term = inverseFact[i];
        if(i % 2 == 0) {
            summation = (summation + term) % MOD;
        } else {
            summation = (summation - term + MOD) % MOD;
        }
    }
    cout << ((res % MOD) * (summation % MOD)) % MOD;
}

int main() {
    fast_cin();
    find();
    levi();
    cout << '\n';
    return 0;
}
