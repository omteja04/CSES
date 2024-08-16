/**
 * Author: omteja04
 * Created on: 01-04-2024 12:16:06
 * Description: Weird_Algorithm
**/

#include <bits/stdc++.h>
#define boo cout << "Boo" << '\n'
using namespace std;
int main() {
    long long n;
    cin >> n;
    while(n!=1){
        cout << n << " ";
        if(n&1) {
            n = n * 3 + 1;
        }
        else{
            n /= 2;
        }
    }
    cout << 1;
    return 0;
}