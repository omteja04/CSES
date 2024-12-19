/**
 * Author: omteja04
 * Created on: 18-12-2024 14:44:59
 * Description: ArrayDivision
 **/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using ll = long long;
bool can(std::vector<ll> &arr, ll k, ll mid) {
    ll cnt = 1;
    ll sum = 0;
    for(ll i = 0; i < arr.size(); i++) {
        if(sum + arr[i] > mid) {
            sum = arr[i];
            cnt++;
        } else {
            sum += arr[i];
        }
    }
    return cnt > k;
}
int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<ll> arr(n);
    for(ll &i: arr) {
        std::cin >> i;
    }
    ll low = *std::max_element(arr.begin(), arr.end());
    ll high = std::accumulate(arr.begin(), arr.end(), 0LL);

    ll ans;
    while(low <= high) {
        ll mid = low + (high - low) / 2;
        if(can(arr, k, mid)) {
            low = mid + 1;
        } else {
            ans = mid;
            high = mid - 1;
        }
    }
    std::cout<< ans;
    return 0;
}
