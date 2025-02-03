/**
 * Author: omteja04
 * Created on: 03-02-2025 10:14:52
 * Description: Subarray_Sums_I
 **/
#include <iostream>
#include <vector>
using ll = long long;
int main() {
    ll n, k;
    std::cin >> n >> k;
    std::vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    ll cnt = 0;
    int sum = 0;
    for(int left = 0, right = 0; right < n;) {

        while(right < n && sum < k) {
            sum += arr[right];
            right++;
        }
        while(left <= right && sum > k) {
            sum -= arr[left];
            left++;
        }
        if(sum == k) {
            cnt++;
            sum -= arr[left];
            left++;
        }
    }
    std::cout << cnt << std::endl;
}
