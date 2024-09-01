/**
 * Author: omteja04
 * Created on: 31-08-2024 15:02:06
 * Description: Static_Range_Sum_Queries
 **/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using v64 = vector<ll>;

// Build segment tree
void buildTree(const v64 &arr, v64 &segmentTree, int start, int end, int idx) {
    if (start == end) {
        segmentTree[idx] = arr[start];
        return;
    }
    int mid = (start + end) >> 1;
    buildTree(arr, segmentTree, start, mid, 2 * idx);
    buildTree(arr, segmentTree, mid + 1, end, 2 * idx + 1);
    segmentTree[idx] = segmentTree[2 * idx] + segmentTree[2 * idx + 1];
}

// Query segment tree for range sum
ll querySearch(const v64 &segmentTree, ll segmentTreeStart, ll segmentTreeEnd, ll queryStart, ll queryEnd, int idx) {
    if (queryStart > queryEnd)
        return 0;

    if (segmentTreeStart == queryStart && segmentTreeEnd == queryEnd) {
        return segmentTree[idx];
    }

    ll mid = (segmentTreeStart + segmentTreeEnd) >> 1;
    ll left = querySearch(segmentTree, segmentTreeStart, mid, queryStart, min(queryEnd, mid), 2 * idx);
    ll right = querySearch(segmentTree, mid + 1, segmentTreeEnd, max(queryStart, mid + 1), queryEnd, 2 * idx + 1);
    return left + right;
}

void levi() {
    int n, q;
    cin >> n >> q;
    v64 arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<ll> segmentTree(4 * n + 1, 0);
    buildTree(arr, segmentTree, 0, n - 1, 1);
    while (q--) {
        int queryStart, queryEnd;
        cin >> queryStart >> queryEnd;
        ll ans = querySearch(segmentTree, 0, n - 1, queryStart - 1, queryEnd - 1, 1);
        cout << ans << "\n";
    }
}

int main() {
    levi();
    return 0;
}
