#include <iostream>
#include <map>
#include <vector>
using ll = long long;
int main() {
    ll n, k;
    std::cin >> n >> k;
    std::vector<ll> arr(n);
    for(auto &it: arr) {
        std::cin >> it;
    }
    std::map<ll, ll> mp;
    mp[0] = 1;
    ll cnt = 0;
    ll sum = 0;
    for(ll i = 0; i < n; i++) {
        sum += arr[i];
        if(mp.find(sum - k) != mp.end()) {
            cnt += mp[sum - k];
        }
        mp[sum]++;
    }
    std::cout << cnt;
}
