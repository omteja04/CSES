/**
 * Author: omteja04
 * Created on: 20-03-2025 20:30:23
 * Problem: RangeUpdateQueries
 * Link: https://cses.fi/problemset/task/1651
 **/

#include <bits/stdc++.h>

using ll = long long;

class SegmentTreeLazy {
private:
    ll n;
    std::vector<ll> tree, lazy;

    void buildTree(ll node, ll start, ll end, const std::vector<ll> &arr) {
        if(start == end) {
            tree[node] = arr[start];
            return;
        }
        ll mid = (start + end) / 2;
        buildTree(2 * node + 1, start, mid, arr);
        buildTree(2 * node + 2, mid + 1, end, arr);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    void passToChild(ll node, ll segmentTreeStart, ll segmentTreeEnd) {
        if(lazy[node] != 0) {
            // Apply lazy update for current node
            tree[node] += lazy[node] * (segmentTreeEnd - segmentTreeStart + 1);
            // Pass lazy to children if not a leaf
            if(segmentTreeStart != segmentTreeEnd) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void rangeUpdate(ll node, ll lazyValue, ll rangeStart, ll rangeEnd, ll segmentTreeStart, ll segmentTreeEnd) {
        passToChild(node, segmentTreeStart, segmentTreeEnd);
        if(rangeStart > segmentTreeEnd || rangeEnd < segmentTreeStart) {
            return;  // No overlap
        }
        if(rangeStart <= segmentTreeStart && segmentTreeEnd <= rangeEnd) {
            // Complete overlap
            lazy[node] += lazyValue;
            passToChild(node, segmentTreeStart, segmentTreeEnd);
            return;
        }
        // Partial overlap
        ll mid = (segmentTreeStart + segmentTreeEnd) / 2;
        rangeUpdate(2 * node + 1, lazyValue, rangeStart, rangeEnd, segmentTreeStart, mid);
        rangeUpdate(2 * node + 2, lazyValue, rangeStart, rangeEnd, mid + 1, segmentTreeEnd);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];  // Update parent after recursion
    }

    ll query(ll node, ll point, ll segmentTreeStart, ll segmentTreeEnd) {
        passToChild(node, segmentTreeStart, segmentTreeEnd);
        if(segmentTreeStart == segmentTreeEnd) {
            return tree[node];
        }
        ll mid = (segmentTreeStart + segmentTreeEnd) / 2;
        if(point <= mid) {
            return query(2 * node + 1, point, segmentTreeStart, mid);
        } else {
            return query(2 * node + 2, point, mid + 1, segmentTreeEnd);
        }
    }

public:
    SegmentTreeLazy(const std::vector<ll> &arr) {
        n = arr.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        buildTree(0, 0, n - 1, arr);
    }

    ll query(ll point) {
        return query(0, point - 1, 0, n - 1);
    }

    void rangeUpdate(ll rangeStart, ll rangeEnd, ll lazyValue) {
        rangeUpdate(0, lazyValue, rangeStart - 1, rangeEnd - 1, 0, n - 1);
    }
};

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for(auto &it: arr) {
        cin >> it;
    }

    SegmentTreeLazy segmentTree(arr);
    while(q--) {
        ll operation;
        cin >> operation;
        if(operation == 2) {
            ll point;
            cin >> point;
            cout << segmentTree.query(point) << "\n";
        } else {
            ll rangeStart, rangeEnd, lazyValue;
            cin >> rangeStart >> rangeEnd >> lazyValue;
            segmentTree.rangeUpdate(rangeStart, rangeEnd, lazyValue);
        }
    }
}
