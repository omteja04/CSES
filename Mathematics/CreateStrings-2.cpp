/**
 * Author: omteja04
 * Created on: 25-02-2025 18:30:48
 * Problem: https://cses.fi/problemset/task/1715/
 **/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;
#define fast_cin()                         \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL);                    \
    std::cout.tie(NULL)
#define int long long
const int MOD = 1e9 + 7;
const int N = 1e6;
vector<ll> fact(N + 1), inverseFact(N + 1);
ll binPow(int x, int y) { 
    ll res = 1;
    while(y > 0) {
        if(y & 1) {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        y >>= 1;
    }
    return res;
}
void find() {
    fact[0] = 1;
    for(int i = 1; i < N + 1; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inverseFact[N] = binPow(fact[N], MOD - 2);
    for(int i = N - 1; i >= 0; i--) {
        inverseFact[i] = inverseFact[i + 1] * (i + 1) % MOD;
    }
}
void levi() {
    string str;
    cin >> str;
    ll n = str.length();
    find();
    unordered_map<char, int> mp;
    for(auto &it: str) {
        mp[it]++;
    }
    ll res = fact[n];
    for(auto &it: mp) {
        res = ((res % MOD) * (inverseFact[it.second] % MOD)) % MOD;
    }
    cout << res;
}
#undef int
int main() {
    fast_cin();
    levi();
    std::cout << '\n';
    return 0;
}
