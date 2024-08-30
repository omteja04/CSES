/**
 * Author: omteja04
 * Created on: 30-08-2024 21:32:29
 * Description: Dynamic_Range_Minimum_Queries
 **/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using v32 = vector<int>;

void buildTree(vector<ll> &arr, vector<ll> &segmentTree, ll idx, ll start, ll end) {
    // Base Case
    if (start == end) {
        segmentTree[idx] = arr[start];
        return;
    }
    int mid = (start + end) >> 1;
    buildTree(arr, segmentTree, 2 * idx, start, mid);
    buildTree(arr, segmentTree, 2 * idx + 1, mid + 1, end);
    segmentTree[idx] = min(segmentTree[2 * idx], segmentTree[2 * idx + 1]);
}

ll querySearch(vector<ll> &segmentTree, int queryStart, int queryEnd, int segmentTreeStart, int segmentTreeEnd, int idx) {
    // No overlap
    if (queryEnd < segmentTreeStart || queryStart > segmentTreeEnd)
        return INT_MAX;
    // Complete Overlap
    if (segmentTreeStart >= queryStart && segmentTreeEnd <= queryEnd)
        return segmentTree[idx];
    // Partial overlap
    int mid = (segmentTreeStart + segmentTreeEnd) >> 1;
    int left = querySearch(segmentTree, queryStart, queryEnd, segmentTreeStart, mid, 2 * idx);
    int right = querySearch(segmentTree, queryStart, queryEnd, mid + 1, segmentTreeEnd, 2 * idx + 1);
    return min(left, right);
}
void update(vector<ll> &segmentTree, ll segmentTreeStart, ll segmentTreeEnd, ll position, ll valueToBeChanged, ll idx) {
    if (segmentTreeStart == segmentTreeEnd) {
        segmentTree[idx] = valueToBeChanged;
        return;
    }
    int mid = (segmentTreeStart + segmentTreeEnd) >> 1;
    if (position <= mid) {
        update(segmentTree, segmentTreeStart, mid, position, valueToBeChanged, 2 * idx);
    } else {
        update(segmentTree, mid + 1, segmentTreeEnd, position, valueToBeChanged, 2 * idx + 1);
    }
    segmentTree[idx] = min(segmentTree[2 * idx], segmentTree[2 * idx + 1]);
}

void levi() {
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // Create SegmentTree DS
    vector<ll> segmentTree(4 * n + 1, INT_MAX);
    buildTree(arr, segmentTree, 1, 0, n - 1);
    while (q--) {
        int parameter;
        cin >> parameter;

        if (parameter == 1) {
            int value, pos;
            cin >> pos >> value;
            update(segmentTree, 0, n - 1, pos - 1, value, 1);
        } else {
            int queryStart, queryEnd;
            cin >> queryStart >> queryEnd;
            int ans = querySearch(segmentTree, queryStart - 1, queryEnd - 1, 0, n - 1, 1);
            cout << ans << "\n";
        }
    }
}

int main() {
    levi();
    return 0;
}