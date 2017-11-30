#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& c, int m, int curr = 0, int cats = 0) {
    vis[curr] = true;

    if(c[curr]) {
        cats++;
    }
    else {
        cats = 0;
    }

    if(cats > m) {
        return 0;
    }

    int total = 0;
    bool leaf = true;
    for(auto i : adj[curr]) {
        if(!vis[i]) {
            total += dfs(adj, vis, c, m, i, cats);
            leaf = false;
        }
    }

    if(leaf) {
        total++;
    }

    return total;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<bool> c;
    for(int i = 0; i < n; i++) {
        int j;
        cin >> j;
        c.push_back(j == 1);
    }

    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        n1--;
        n2--;

        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    vector<bool> vis(n, false);
    cout << dfs(adj, vis, c, m) << endl;
}
