/**
 * Author: omteja04
 * Created on: 21-01-2025 20:41:26
 * Description: SlidingWindowMedian
 **/

#include <iostream>
#include <iterator>
#include <set>
#include <vector>
std::vector<long long> medianSlidingWindow(std::vector<long long> &nums, int k) {
    std::vector<long long> res;
    std::multiset<long long> low, high;

    auto balance = [&] {
        if(low.size() > high.size() + 1) {
            high.insert(*low.rbegin());
            low.erase(std::prev(low.end()));
        } else if(high.size() > low.size()) {
            low.insert(*high.begin());
            high.erase(high.begin());
        }
    };

    for(int i = 0; i < nums.size(); i++) {
        // insertion
        if(low.empty() || nums[i] <= *low.rbegin()) {
            low.emplace(nums[i]);
        } else {
            high.emplace(nums[i]);
        }
        balance();
        // deletion
        if(i >= k) {
            int val = nums[i - k];
            if(val <= *low.rbegin()) {
                low.erase(low.find(val));
            } else {
                high.erase(high.find(val));
            }
        }
        balance();
        if(i >= k - 1) {
            res.emplace_back((long long) *prev(low.end()));
        }
    }

    return res;
}
int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<long long> arr(n);
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::vector<long long> res = medianSlidingWindow(arr, k);
    for(int i = 0; i < res.size(); i++) {
        std::cout << res[i] << " ";
    }
}
