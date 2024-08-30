/**
 * Author: omteja04
 * Created on: 02-04-2024 18:32:56
 * Description: Missing_Number
 **/

#include <bits/stdc++.h>
#define boo cout << "Boo" << '\n'
using namespace std;
int main() {
    long long n;
    cin >> n;
    vector<long long> nums(n - 1);
    long long sum = 0LL;
    for (long long i = 0; i < n - 1; i++) {
        cin >> nums[i];
        sum += nums[i];
    }
    // sum = accumulate(nums.begin(), nums.end(), 0LL);
    long long aSum = (n *(n + 1)) >> 1;
    cout << aSum - sum << endl;

    return 0;
}