/**
 * Author: omteja04
 * Created on: 02-04-2024 18:31:24
 * Description: Trailing_Zeros
 **/

#include <bits/stdc++.h>
#define boo cout << "Boo" << '\n'
using namespace std;
int main() {
    int n, sum = 0, k;
    cin >> n;
    int i;
    for (i = 1; i < n; i++) {
        k = n / (pow(5, i));
        if (k == 0)
            break;
        sum += k;
    }
    cout << sum << endl;
    return 0;
}