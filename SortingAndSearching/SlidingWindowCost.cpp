/**
 * Author: omteja04
 * Created on: 21-01-2025 18:00:57
 * Description: SlidingWindowCost
 **/

#include <iostream>
#include <iterator>
#include <set>
#include <vector>
std::vector<long long> costOfWindow(std::vector<long long> &nums, int k) {
    std::vector<long long> res;
    std::multiset<long long> low, high;
    long long lowSum = 0;
    long long highSum = 0;

    auto balance = [&] {
        if(low.size() > high.size() + 1) {
            high.insert(*low.rbegin());
            highSum += *low.rbegin();
            lowSum -= *low.rbegin();
            low.erase(std::prev(low.end()));
        } else if(high.size() > low.size()) {
            low.insert(*high.begin());
            lowSum += *high.begin();
            highSum -= *high.begin();
            high.erase(high.begin());
        }
    };

    for(int i = 0; i < (int) nums.size(); i++) {
        // insertion
        if(low.empty() || nums[i] <= *low.rbegin()) {
            low.emplace(nums[i]);
            lowSum += nums[i];
        } else {
            high.emplace(nums[i]);
            highSum += nums[i];
        }
        balance();
        // deletion
        if(i >= k) {
            int val = nums[i - k];
            if(val <= *low.rbegin()) {
                lowSum -= val;
                low.erase(low.find(val));
            } else {
                highSum -= val;
                high.erase(high.find(val));
            }
        }
        balance();
        if(i >= k - 1) {
            long long median = *low.rbegin();
            // std::cerr << median << std::endl;
            long long ans1 = (median * low.size() - lowSum);
            long long ans2 = (highSum - (median * high.size()));
            res.push_back(ans1 + ans2);
        }
    }

    return res;
}
int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<long long> arr(n);
    for(int i = 0; i < (int) n; i++) {
        std::cin >> arr[i];
    }

    std::vector<long long> ans = costOfWindow(arr, k);
    for(int i = 0; i < (int) ans.size(); i++) {
        std::cout << ans[i] << " ";
    }
}
