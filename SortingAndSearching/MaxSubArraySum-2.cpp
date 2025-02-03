/**
 * Author: omteja04
 * Created on: 21-01-2025 21:50:01
 * Description: MaxSubArraySum-2
 **/

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
int main() {
    int n, a, b;
    std::cin >> n >> a >> b;
    std::vector<long long> arr(n);
    for(auto &it: arr) {
        std::cin >> it;
    }
    std::vector<long long> prefix(n + 1, 0);

    for(int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }
    long long ans = LLONG_MIN;
    std::multiset<long long> ms;
    for(int i = a; i <= n; i++) {
        if(i > b) {
            ms.erase(ms.find(prefix[i - b - 1]));
        }
        ms.insert(prefix[i - a]);
        ans = std::max(ans, prefix[i] - *ms.begin());
    }
    std::cout << ans;
}
