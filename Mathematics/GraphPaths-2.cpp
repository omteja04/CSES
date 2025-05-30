/**
 * Author: omteja04
 * Created on: 30-05-2025 22:08:47
 * Problem: GraphPaths-2
 * Link: https://cses.fi/problemset/task/1724
 **/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = LLONG_MAX / 2;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

using Matrix = vector<vector<ll>>;

Matrix operator*(Matrix &a, Matrix &b) {
    ll n = a.size();
    Matrix res(n, vector<ll>(n, INF));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(a[i][k] < INF && b[k][j] < INF) {
                    res[i][j] = min(res[i][j], a[i][k] + b[k][j]);
                }
            }
        }
    }
    return res;
}

Matrix generateIdentity(ll n) {
    Matrix I(n, vector<ll>(n, INF));
    for(int i = 0; i < n; ++i) {
        I[i][i] = 0;
    }
    return I;
}

Matrix power(Matrix base, ll exp) {
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

    Matrix adj(vertices, vector<ll>(vertices, INF));
    for(int i = 0; i < edgeCnt; i++) {
        ll u, v, c;
        cin >> u >> v >> c;
        adj[u - 1][v - 1] = min(adj[u - 1][v - 1], c);
    }

    Matrix res = power(adj, pathLength);
    ll ans = INF;
    ans = res[0][vertices - 1];

    if(ans >= INF / 2) {
        cout << -1;
    } else {
        cout << ans;
    }
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
