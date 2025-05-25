/**
 * Author: omteja04
 * Created on: 24-05-2025 22:17:10
 * Problem: LearnLazy
 **/

#include <algorithm>
#include <bits/stdc++.h>

using ll = long long;

class SegmentTreeForRangeUpdate {
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

    ll pointQuery(ll node, ll point, ll segmentTreeStart, ll segmentTreeEnd) {
        passToChild(node, segmentTreeStart, segmentTreeEnd);
        if(segmentTreeStart == segmentTreeEnd) {
            return tree[node];
        }
        ll mid = (segmentTreeStart + segmentTreeEnd) / 2;
        if(point <= mid) {
            return pointQuery(2 * node + 1, point, segmentTreeStart, mid);
        } else {
            return pointQuery(2 * node + 2, point, mid + 1, segmentTreeEnd);
        }
    }
    ll rangeSumQuery(ll node, ll rangeStart, ll rangeEnd, ll segmentTreeStart, ll segmentTreeEnd) {
        passToChild(node, segmentTreeStart, segmentTreeEnd);
        if(rangeStart > segmentTreeEnd || rangeEnd < segmentTreeStart) {
            return 0;
        }
        if(rangeStart <= segmentTreeStart && segmentTreeEnd <= rangeEnd) {
            return tree[node];
        }
        ll mid = (segmentTreeStart + segmentTreeEnd) / 2;
        return rangeSumQuery(2 * node + 1, rangeStart, rangeEnd, segmentTreeStart, mid) +
          rangeSumQuery(2 * node + 2, rangeStart, rangeEnd, mid + 1, segmentTreeEnd);
    }

public:
    SegmentTreeForRangeUpdate(const std::vector<ll> &arr) {
        n = arr.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        buildTree(0, 0, n - 1, arr);
    }

    ll getPoint(ll point) {
        return pointQuery(0, point - 1, 0, n - 1);
    }
    ll getRangeSum(ll rangeStart, ll rangeEnd) {
        return rangeSumQuery(0, rangeStart - 1, rangeEnd - 1, 0, n - 1);
    }
    void updateRange(ll rangeStart, ll rangeEnd, ll lazyValue) {
        rangeUpdate(0, lazyValue, rangeStart - 1, rangeEnd - 1, 0, n - 1);
    }
};

class SegmentTreeForRangeMinimalUpdate {
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
        tree[node] = std::min(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void passToChild(ll node, ll segmentTreeStart, ll segmentTreeEnd) {
        if(lazy[node] != 0) {
            // Apply lazy update for current node
            tree[node] += lazy[node];
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
        tree[node] = std::min(tree[2 * node + 1], tree[2 * node + 2]);  // Update parent after recursion
    }

    ll pointQuery(ll node, ll point, ll segmentTreeStart, ll segmentTreeEnd) {
        passToChild(node, segmentTreeStart, segmentTreeEnd);
        if(segmentTreeStart == segmentTreeEnd) {
            return tree[node];
        }
        ll mid = (segmentTreeStart + segmentTreeEnd) / 2;
        if(point <= mid) {
            return pointQuery(2 * node + 1, point, segmentTreeStart, mid);
        } else {
            return pointQuery(2 * node + 2, point, mid + 1, segmentTreeEnd);
        }
    }
    ll rangeMinQuery(ll node, ll rangeStart, ll rangeEnd, ll segmentTreeStart, ll segmentTreeEnd) {
        passToChild(node, segmentTreeStart, segmentTreeEnd);
        if(rangeStart > segmentTreeEnd || rangeEnd < segmentTreeStart) {
            return INT_MAX;
        }
        if(rangeStart <= segmentTreeStart && segmentTreeEnd <= rangeEnd) {
            return tree[node];
        }
        ll mid = (segmentTreeStart + segmentTreeEnd) / 2;
        return std::min(
          rangeMinQuery(2 * node + 1, rangeStart, rangeEnd, segmentTreeStart, mid),
          rangeMinQuery(2 * node + 2, rangeStart, rangeEnd, mid + 1, segmentTreeEnd));
    }

public:
    SegmentTreeForRangeMinimalUpdate(const std::vector<ll> &arr) {
        n = arr.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        buildTree(0, 0, n - 1, arr);
    }

    ll getPoint(ll point) {
        return pointQuery(0, point - 1, 0, n - 1);
    }
    ll getRangeMinimum(ll rangeStart, ll rangeEnd) {
        return rangeMinQuery(0, rangeStart - 1, rangeEnd - 1, 0, n - 1);
    }
    void updateRange(ll rangeStart, ll rangeEnd, ll lazyValue) {
        rangeUpdate(0, lazyValue, rangeStart - 1, rangeEnd - 1, 0, n - 1);
    }
};
