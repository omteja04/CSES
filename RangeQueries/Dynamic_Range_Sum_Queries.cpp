/**
 * Author: omteja04
 * Created on: 10-03-2025 23:13:11
 * Problem: Dynamic_Range_Sum_Queries
 * Link: https://cses.fi/problemset/task/1648
 **/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using vi = vector<ll>;

class SegmentTree {
private:
    ll n;
    vector<ll> segmentTree;
    ll makeQuery(ll segmentTreeStart, ll segmentTreeEnd, ll queryStart, ll queryEnd, ll node) {
        if(queryStart > segmentTreeEnd || queryEnd < segmentTreeStart) {
            return 0;
        }
        if(queryStart <= segmentTreeStart && queryEnd >= segmentTreeEnd) {
            return segmentTree[node];
        }
        ll mid = segmentTreeStart + (segmentTreeEnd - segmentTreeStart) / 2;
        ll left = makeQuery(segmentTreeStart, mid, queryStart, queryEnd, 2 * node);
        ll right = makeQuery(mid + 1, segmentTreeEnd, queryStart, queryEnd, 2 * node + 1);
        return left + right;
    }
    void updateQuery(ll node, ll pos, ll valueToBeChanged, ll segSt, ll segEnd) {
        if(segSt == segEnd) {
            segmentTree[node] = valueToBeChanged;
            return;
        }
        ll mid = segSt + (segEnd - segSt) / 2;
        if(pos <= mid) {
            updateQuery(2 * node, pos, valueToBeChanged, segSt, mid);
        } else {
            updateQuery(2 * node + 1, pos, valueToBeChanged, mid + 1, segEnd);
        }
        segmentTree[node] = segmentTree[2 * node] + segmentTree[2 * node + 1];
    }

public:
    SegmentTree(vector<ll> &arr) {
        n = arr.size();
        segmentTree.resize(4 * n + 1, 0);
        buildTree(arr, 1, 0, n - 1);
    }
    void buildTree(vector<ll> &arr, ll node, ll start, ll end) {
        if(start == end) {
            segmentTree[node] = arr[start];
            return;
        }
        ll mid = start + (end - start) / 2;
        buildTree(arr, 2 * node, start, mid);
        buildTree(arr, 2 * node + 1, mid + 1, end);
        segmentTree[node] = segmentTree[2 * node] + segmentTree[2 * node + 1];
    }
    ll find(ll queryStart, ll queryEnd) {
        return makeQuery(0, n - 1, queryStart, queryEnd, 1);
    }
    void update(long long position, long long valueToBeChanged) {
        updateQuery(1, position, valueToBeChanged, 0, n - 1);
    }
};

int main() {
    ll n, q;
    cin >> n >> q;
    std::vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    SegmentTree tree(arr);
    while(q--) {
        ll op;
        std::cin >> op;
        if(op == 1) {

            ll pos, val;
            std::cin >> pos >> val;
            tree.update(pos - 1, val);

        } else {

            ll queryStart, queryEnd;
            std::cin >> queryStart >> queryEnd;
            ll ans = tree.find(queryStart - 1, queryEnd - 1);
            std::cout << ans << "\n";
        }
    }
}
