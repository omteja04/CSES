/**
 * Author: omteja04
 * Created on: 24-08-2024 12:14:49
 * Description: Counting_Divisors
 **/

#include <iostream>
#include <vector>
int countDivisors(int n) {
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            if (i != n / i) {
                cnt++;
            }
        }
    }
    return cnt;
}
int main() {
    int tc;
    std::cin >> tc;
    while (tc--) {
        int n;
        std::cin >> n;
        std::cout << countDivisors(n) << std::endl;
    }
}