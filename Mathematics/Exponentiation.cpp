/**
 * Author: omteja04
 * Created on: 28-01-2025 18:25:37
 * Description: Exponentiation
 **/

#include <iostream>
const int MOD = 1000000007;
long long power(long long a, long long b) {
    if(b == 0) {
        return 1;
    }
    long long res = power(a, b / 2);
    // std::cerr << res << " ";
    if(b & 1) {
        res = res % MOD * res % MOD * a % MOD;
    } else {
        res = res % MOD * res % MOD;
    }
    return res;
}
int main() {
    int n;
    std::cin >> n;
    while(n--) {
        long long a, b;
        std::cin >> a >> b;
        long long res = power(a, b);
        std::cout << res << std::endl;
    }
}
