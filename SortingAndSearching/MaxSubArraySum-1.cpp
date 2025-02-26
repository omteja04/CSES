/**
 * Author: omteja04
 * Created on: 21-01-2025 21:50:01
 * Description: MaxSubArraySum-2
 **/

#include <algorithm>
#include <iostream>
#include <vector>
int main() {
    int n;
    std::cin >> n;
    std::vector<long long> arr(n);
    for(auto &it: arr) {
        std::cin >> it;
    }
    std::vector<long long> prefix(n + 1, 0);

    for(int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }
    long long ans = prefix[1];
    long long minimumSum = prefix[0];
    for(int i = 1; i <= n; i++) {
        ans = std::max(ans, prefix[i] - minimumSum);
        minimumSum = std::min(minimumSum, prefix[i]);
    }

    std::cout << ans;
}
