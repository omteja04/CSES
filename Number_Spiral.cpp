#include <bits/stdc++.h>
#define boo cout << "Boo" << '\n'
using namespace std;
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)

long long calculateDiagonal(long long diag) {
    long long result = diag * diag - (diag - 1);
    return result;
}
void teja() {
    long long x, y;
    cin >> x >> y;
    long long result;

    if (x == y) {
        result = calculateDiagonal(x);
    } else if (x > y) {
        result = calculateDiagonal(x);
        if (x & 1)
            result = result - (x - y);
        else
            result = result + (x - y);
    } else {
        result = calculateDiagonal(y);
        if (y & 1)
            result = result - (x - y);
        else
            result = result + (x - y);
    }
    cout << result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    tc {
        teja();
        cout << '\n';
    }
    return 0;
}