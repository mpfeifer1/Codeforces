#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<int>>& adj, vector<bool>& vis, int curr, int ban1, int ban2) {
    if(vis[curr]) {
        return 0;
    }

    int best = 0;
    vis[curr] = true;
    for(auto i : adj[curr]) {
        if(curr == ban1 && i == ban2) {
            continue;
        }
        if(curr == ban2 && i == ban1) {
            continue;
        }
        best = max(best, dfs(adj, vis, i, ban1, ban2));
    }

    return best + 1;
}

int getlen(vector<vector<int>>& adj, int ban1, int ban2) {
    // See what can be reached on either side
    int n = adj.size();
    vector<bool> vis(n, false);
    dfs(adj, vis, ban1, ban1, ban2);

    // Split into sides
    vector<int> l;
    vector<int> r;
    for(int i = 0; i < vis.size(); i++) {
        if(vis[i]) {
            l.push_back(i);
        }
        else {
            r.push_back(i);
        }
    }

    // Find best on left
    int bestl = 0;
    for(auto i : l) {
        fill(vis.begin(), vis.end(), false);
        bestl = max(bestl, dfs(adj, vis, i, ban1, ban2));
    }

    // Find best on right
    int bestr = 0;
    for(auto i : r) {
        fill(vis.begin(), vis.end(), false);
        bestr = max(bestr, dfs(adj, vis, i, ban1, ban2));
    }

    bestl--;
    bestr--;

    // Return answer
    return bestl * bestr;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    vector<pair<int,int>> edges;

    for(int i = 0; i < n-1; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--;
        n2--;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
        edges.push_back({n1,n2});
    }

    int best = 0;
    for(auto i : edges) {
        best = max(best, getlen(adj, i.first, i.second));
    }

    cout << best << endl;
}
