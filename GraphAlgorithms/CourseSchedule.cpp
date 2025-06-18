/**
 * Author: omteja04
 * Created on: 18-06-2025 08:15:52
 * Problem: CourseSchedule
 * Link: https://cses.fi/problemset/task/1679
 **/
#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
#define fast_cin()                         \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL);                    \
    std::cout.tie(NULL)

vector<int> usingBFS(int n, vector<pair<int, int>> &edges) {
    vector<vector<int>> adj(n + 1);
    vector<int> inDegree(n + 1, 0);
    for(auto &pair: edges) {
        adj[pair.first].push_back(pair.second);
        inDegree[pair.second]++;
    }

    queue<int> q;
    vector<int> res;

    inDegree[0] = INT_MAX;

    for(int i = 1; i <= n; i++) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        res.push_back(node);
        for(auto neighbour: adj[node]) {
            if(--inDegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }
    if(res.size() == n) {
        return res;
    }
    return {};
}
// Helper for DFS with cycle detection
bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &res) {
    vis[node] = 1;  // visiting
    for(int neighbor: adj[node]) {
        if(vis[neighbor] == 1) {
            return false;  // cycle
        }
        if(vis[neighbor] == 0 && !dfs(neighbor, adj, vis, res)) {
            return false;
        }
    }
    vis[node] = 2;  // visited
    res.push_back(node);
    return true;
}

vector<int> usingDFS(int n, vector<pair<int, int>> &edges) {
    vector<vector<int>> adj(n + 1);
    for(auto &pair: edges) {
        adj[pair.first].push_back(pair.second);
    }

    vector<int> vis(n + 1, 0);  // 0 = unvisited, 1 = visiting, 2 = visited
    vector<int> res;

    for(int i = 1; i <= n; ++i) {
        if(vis[i] == 0) {
            if(!dfs(i, adj, vis, res)) {
                return {};  // cycle found
            }
        }
    }

    reverse(res.begin(), res.end());
    return res;
}
void levi() {
    int n, m;
    cin >> n >> m;
    // course a has to be completed before course b
    vector<pair<int, int>> edges(m);
    for(auto &pair: edges) {
        cin >> pair.first >> pair.second;
    }
    vector<int> res;

    // using BFS
    // === Choose one method below ===
    // res = usingBFS(n, edges); // BFS (Kahn's)
    res = usingDFS(n, edges);  // DFS with cycle detection

    if(res.empty()) {
        cout << "IMPOSSIBLE\n";
    } else {
        for(int course: res) {
            cout << course << ' ';
        }
        cout << '\n';
    }
}

int main() {
    fast_cin();
    int tc = 1;
    while(tc--) {
        levi();
        cout << '\n';
    }
    return 0;
}
