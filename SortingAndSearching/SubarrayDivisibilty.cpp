/**
 * Author: omteja04
 * Created on: 14-03-2025 21:18:52
 * Problem: SubarrayDivisibilty
 * Link: https://cses.fi/problemset/task/1662
 **/
#include <bits/stdc++.h>
#include <map>
#include <vector>
using namespace std;
using ll = long long;
signed main() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll cnt = 0;
    ll prefix = 0;
    map<ll, ll> mp;
    mp[0] = 1;
    for(ll i = 0; i < n; i++) {
        prefix += arr[i];
        ll rem = prefix % n;
        if(rem < 0) {
            rem += n;
        }
        mp[rem]++;
    }
    for(auto &it: mp) {
        ll value = it.second;
        // ll key = it.first;
        cnt += (value * (value - 1) / 2);
    }
    cout << cnt;
}
