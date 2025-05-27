/**
 * Author: omteja04
 * Created on: 27-05-2025 21:31:21
 * Problem: FibonacciNumbers
 * Link: https://cses.fi/problemset/task/1722
 **/

#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;
using Matrix = vector<vector<ll>>;
const int MOD = 1e9 + 7;
#define fast_cin()                         \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL);                    \
    std::cout.tie(NULL)

Matrix multiply(const Matrix &a, Matrix &b) {
    ll n = a.size();
    Matrix res(n, vector<ll>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return res;
}
Matrix power(Matrix &base, ll exp) {
    ll n = base.size();
    Matrix res(n, vector<ll>(n));
    for(int i = 0; i < n; i++) {
        res[i][i] = 1;
    }
    while(exp) {
        if(exp & 1) {
            res = multiply(res, base);
        }
        base = multiply(base, base);
        exp >>= 1;
    }
    return res;
}

void levi() {
    ll n;
    cin >> n;
    Matrix T = {{1, 1}, {1, 0}};
    if(n == 0) {
        cout << 0;
        return;
    }
    Matrix res = power(T, n - 1);
    cout << res[0][0];
}

int main() {
    fast_cin();
    int tc = 1;
    // cin >> tc;
    while(tc--) {
        levi();
        cout << '\n';
    }
    return 0;
}
