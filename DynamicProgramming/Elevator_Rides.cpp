/**
 * Author: omteja04
 * Created on: 24-08-2024 00:12:56
 * Description: Elevator_Rides
 **/

// www.cses.fi/problemset/task/1653
#include <algorithm>
#include <iostream>
#include <vector>
int main() {
    long long people, maxWeight;
    std::cin >> people >> maxWeight;
    std::vector<long long> weight(people);
    for (int i = 0; i < people; i++) {
        std::cin >> weight[i];
    }
    std::vector<std::pair<int, long long>> dp(1 << people, {people + 1, maxWeight + 1});

    dp[0] = std::make_pair(1, 0);
    for (int mask = 1; mask < (1 << people); mask++) {
        for (int i = 0; i < people; i++) {
            if (mask & (1 << i)) { // person using lift
                auto prev = dp[mask - (1 << i)];
                int rideCnt = prev.first;
                long long weightUpto = prev.second;
                if (weightUpto + weight[i] <= maxWeight) {
                    weightUpto += weight[i];
                } else {
                    rideCnt++;
                    weightUpto = weight[i];
                }
                dp[mask] = std::min(dp[mask], std::make_pair(rideCnt, weightUpto));
            }
        }
    }
    std::cout << dp[(1 << people) - 1].first;
}