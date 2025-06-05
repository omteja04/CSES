/**
 * Author: omteja04
 * Created on: 05-06-2025 16:31:01
 * Problem: RepeatingSubstring
 * Link: https://cses.fi/problemset/task/2106/
 **/

#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

using ll = long long;
const int MOD = 1e9 + 7;  // Large prime modulus
const int BASE = 31;      // Base for polynomial hash
                          //
inline ll modAdd(ll a, ll b, const ll mod = MOD) {
    a %= mod;
    b %= mod;
    return (a + b) % mod;
}

inline ll modSub(ll a, ll b, const ll mod = MOD) {
    a %= mod;
    b %= mod;
    return (a - b + mod) % mod;
}

inline ll modMul(ll a, ll b, const ll mod = MOD) {
    a %= mod;
    b %= mod;
    return (a * b) % mod;
}

inline ll power(ll base, ll exp, const ll mod = MOD) {
    ll res = 1;
    base %= mod;
    while(exp > 0) {
        if(exp & 1) {
            res = modMul(res, base, mod);
        }
        base = modMul(base, base, mod);
        exp >>= 1;
    }
    return res;
}

inline ll modInverse(ll a, ll m = MOD) {
    return power(a, m - 2, m);
}

struct SingleHash {
    string s;
    int n;
    vector<ll> prefixHash;
    vector<ll> power;

    SingleHash(const string &str) {
        s = ' ' + str;
        n = (int) s.size();
        prefixHash.resize(n + 1, 0);
        power.resize(n + 1, 1);

        for(int i = 1; i <= n; i++) {
            power[i] = modMul(power[i - 1], BASE, MOD);
            prefixHash[i] = modAdd(modMul(prefixHash[i - 1], BASE, MOD), s[i] - 'a' + 1, MOD);
        }
    }

    ll getHash(int l, int r) {
        //  ll hashValue = prefixHash[r + 1] - (prefixHash[l] * power[r - l + 1]) % MOD;
        ll hashValue = modSub(prefixHash[r], modMul(prefixHash[l - 1], power[r - l + 1], MOD), MOD);
        return hashValue;
    }
    ll fullHash() {
        return getHash(1, n);
    }
};

string longestDupSubstring(string &s) {
    int n = s.size();
    SingleHash hash(s);
    int left = 1;
    int right = n - 1;
    string ans = "";

    auto can = [&](int mid) -> string {
        unordered_map<ll, vector<ll>> mp;
        for(int i = 0; i + mid <= n; i++) {
            ll h = hash.getHash(i + 1, i + mid);

            for(int startIdx: mp[h]) {
                if(s.substr(startIdx, mid) == s.substr(i, mid)) {
                    return s.substr(startIdx, mid);
                }
            }
            mp[h].push_back(i);
        }
        return "";
    };
    while(left <= right) {
        int mid = left + (right - left) / 2;
        string dup = can(mid);
        if(dup.size() > ans.size()) {
            ans = dup;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    fast_cin();
    string str;
    cin >> str;
    string res = longestDupSubstring(str);
    if(res.empty()) {
        cout << -1;
        return 0;
    }
    cout << res;
}
