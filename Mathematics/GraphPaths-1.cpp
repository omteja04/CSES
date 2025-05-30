/**
 * Author: omteja04
 * Created on: 30-05-2025 21:57:04
 * Problem: GraphPaths-1
 * Link: https://cses.fi/problemset/task/1723
 **/

#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
#define fast_cin()                         \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL);                    \
    std::cout.tie(NULL)

using Matrix = vector<vector<ll>>;
Matrix operator*(Matrix &a, Matrix &b) {
    ll n = a.size();
    Matrix res(n, vector<ll>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
            }
        }
    }
    return res;
}

Matrix generateIdentity(ll n) {
    Matrix I(n, vector<long long>(n, 0));
    for(int i = 0; i < n; ++i) {
        I[i][i] = 1;
    }
    return I;
}
Matrix power(Matrix &base, ll exp) {
    Matrix res = generateIdentity(base.size());
    while(exp) {
        if(exp & 1) {
            res = res * base;
        }
        base = base * base;
        exp >>= 1;
    }
    return res;
}
void levi() {
    ll vertices, edgeCnt, pathLength;
    cin >> vertices >> edgeCnt >> pathLength;
    vector<pair<ll, ll>> edges(edgeCnt);
    for(int i = 0; i < edgeCnt; i++) {
        cin >> edges[i].first >> edges[i].second;
    }
    Matrix adj(vertices, vector<ll>(vertices, 0));
    for(auto &it: edges) {
        auto src = it.first;
        auto dest = it.second;
        adj[src - 1][dest - 1]++;
    }
    Matrix res = power(adj, pathLength);
    ll ans = res[0][vertices - 1];
    // for(auto &row: res) {
    //     for(auto &val: row) {
    //         ans = (ans + val) % MOD;
    //     }
    // }
    cout << ans;
}

int main() {
    fast_cin();
    int tc = 1;
    while(tc--) {
        levi();
        cout << '\n';
    }
    return 0;
}
