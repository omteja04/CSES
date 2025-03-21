/**
 * Author: omteja04
 * Created on: 21-03-2025 20:54:55
 * Problem: TrafficLights
 * Link: https://cses.fi/problemset/task/1163
 **/
#include <bits/stdc++.h>
#include <set>
using namespace std;
using ll = long long;
#define fast_cin()                         \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL);                    \
    std::cout.tie(NULL)

void levi() {
    ll x, n;
    cin >> x >> n;
    set<ll> positionsOfLights = {0, x};
    multiset<ll> lengths = {x};
    for(ll i = 0; i < n; i++) {
        ll light;
        cin >> light;
        auto it = positionsOfLights.lower_bound(light);
        ll nextLight = *it;
        ll previousLight = *prev(it);

        lengths.erase(lengths.find(nextLight - previousLight));
        lengths.insert(light - previousLight);
        lengths.insert(nextLight - light);
        positionsOfLights.insert(light);
        cout << *lengths.rbegin() << " ";
    }
}

int main() {
    fast_cin();
    int tc = 1;
    // cin >> tc;
    while(tc--) {
        levi();
        cout << '\n';
    }
    return 0;
}
