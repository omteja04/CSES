/**
 * Author: omteja04
 * Created on: 19-03-2025 18:33:47
 * Problem: Range_XOR_Queries
 * Link: https://cses.fi/problemset/task/1650
 **/

#include <bits/stdc++.h>
#include <vector>
using namespace std;
class SegmentTree {
private:
    long long n;
    std::vector<long long> segmentTree;

    long long query(long long node, long long segmentTreeStart, long long segmentTreeEnd, long long queryStart, long long queryEnd) {
        // No overlap
        if(queryStart > segmentTreeEnd || queryEnd < segmentTreeStart) {
            return 0;
            // return 0;
        }
        // Full Overlap
        if(queryStart <= segmentTreeStart && queryEnd >= segmentTreeEnd) {
            return segmentTree[node];
        }
        // Partial Overlap
        long long mid = segmentTreeStart + (segmentTreeEnd - segmentTreeStart) / 2;
        long long left = query(2 * node + 1, segmentTreeStart, mid, queryStart, queryEnd);
        long long right = query(2 * node + 2, mid + 1, segmentTreeEnd, queryStart, queryEnd);
        return (left ^ right);
    }

    void update(long long node, long long position, long long valueToBeChanged, long long segmentTreeStart, long long segmentTreeEnd) {
        if(segmentTreeStart == segmentTreeEnd) {
            segmentTree[node] = valueToBeChanged;
            return;
        }
        long long mid = segmentTreeStart + (segmentTreeEnd - segmentTreeStart) / 2;
        if(position <= mid) {
            update(2 * node + 1, position, valueToBeChanged, segmentTreeStart, mid);
        } else {
            update(2 * node + 2, position, valueToBeChanged, mid + 1, segmentTreeEnd);
        }
        segmentTree[node] = (segmentTree[2 * node + 1] ^ segmentTree[2 * node + 2]);
    }

    void buildTree(const std::vector<long long> &arr, long long node, long long start, long long end) {
        if(start == end) {
            segmentTree[node] = arr[start];
            return;
        }
        long long mid = start + (end - start) / 2;
        buildTree(arr, 2 * node + 1, start, mid);
        buildTree(arr, 2 * node + 2, mid + 1, end);
        segmentTree[node] = (segmentTree[2 * node + 1] ^ segmentTree[2 * node + 2]);
    }

public:
    SegmentTree(const std::vector<long long> &arr) {
        n = arr.size();
        segmentTree.resize(4 * n, 0);
        // segmentTree.resize(4 * n, 0);
        buildTree(arr, 0, 0, n - 1);
    }

    void update(long long position, long long valueToBeChanged) {
        update(0, position, valueToBeChanged, 0, n - 1);
    }

    long long query(long long queryStart, long long queryEnd) {
        return query(0, 0, n - 1, queryStart, queryEnd);
    }
};

using ll = long long;
int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    SegmentTree tree(arr);

    while(q--) {
        int l, r;
        cin >> l >> r;
        ll ans = tree.query(l - 1, r - 1);
        cout << ans << "\n";
    }
}
