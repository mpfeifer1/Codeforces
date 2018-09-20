#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> tree;

int LOG = 21;

// Calculate depth + size for all nodes
void dfs_lca(tree& adj, vector<int>& depth, vector<bool>& visited, vector<int>& parent, vector<int>& size, int node, int Depth = 0) {
    depth[node] = Depth;
    visited[node] = true;
    size[node] = 1;
    for(int x : adj[node]) {
        if(!visited[x]) {
            parent[x] = node;
            dfs_lca(adj, depth, visited, parent, size, x, Depth+1);
            size[node] += size[x];
        }
    }
}

// Return Nth parent
int par(vector<vector<int>>& memo, int x, int n) {
    for(int k = LOG; k >= 0; --k) {
        if(n & (1 << k)) {
            x = memo[x][k];
            if(x == -1) return x;
        }
    }
    return x;
}

// Builds LCA table
void build(vector<vector<int>>& memo, vector<int>& parent) {
    int n = parent.size();
    for(int i = 0; i < n; ++i) memo[i][0] = parent[i];
    for(int k = 1; k < LOG; ++k) {
        for(int i = 0; i < n; ++i) {
            if(memo[i][k-1] == -1) {
                memo[i][k] = -1;
                continue;
            }
            memo[i][k] = memo[memo[i][k-1]][k-1];
        }
    }
}

// Calculate depth + conversion for all nodes
int current_count = 0;
void dfs_conv(tree& adj, vector<bool>& visited, vector<int>& conv, int node) {
    visited[node] = true;
    conv[node] = current_count;
    current_count++;
    for(int x : adj[node]) {
        if(!visited[x]) {
            dfs_conv(adj, visited, conv, x);
        }
    }
}

// Returns a new tree with renumbered vertices
void renumber(tree& t, vector<int>& roots, vector<int>& conv) {
    // Allocate memory
    int n = t.size();
    vector<bool> vis(n, false);

    // Fill in conversion
    for(auto i : roots) {
        dfs_conv(t, vis, conv, i);
    }

    // Make a new tree, copy edges
    tree adj(n);
    for(int i = 0; i < n; i++) {
        int n1 = conv[i];
        for(auto j : t[i]) {
            int n2 = conv[j];

            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }
    }

    // Set old tree to new tree
    t = adj;

    // Renumber the roots
    for(auto& i : roots) {
        i = conv[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    // Read in tree
    int n;
    cin >> n;
    vector<int> roots;
    tree adj(n);
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        t--;
        if(t != -1) {
            adj[i].push_back(t);
            adj[t].push_back(i);
        }
        else {
            roots.push_back(i);
        }
    }

    // Renumber the tree
    vector<int> conv(n);
    renumber(adj, roots, conv);

    // DFS from each root to get depth, parent, and size of subtree
    vector<int> size(n);
    vector<int> depth(n);
    vector<int> parent(n);
    vector<bool> visited(n,false);
    for(auto i : roots) {
        parent[i] = -1;
        dfs_lca(adj, depth, visited, parent, size, i);
    }

    // Build LCA Table
    vector<vector<int>> memo(n+1, vector<int>(LOG+1,-1));
    build(memo, parent);

    // Calculate depths
    vector<vector<int>> atdepth(n);
    for(int i = 0; i < n; i++) {
        atdepth[depth[i]].push_back(i);
    }

    // For each query
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        // Don't forget to decrement index
        int v, p;
        cin >> v >> p;
        v--;
        v = conv[v];

        // Find pth parent
        v = par(memo, v, p);
        if(v == -1) {
            cout << 0 << " ";
            continue;
        }

        // Find actual depth
        int d = depth[v] + p;

        // Find biggest and lowest children we want
        int lo = v+1;
        int hi = v+size[v];

        // Find their spots in the array
        auto idx1 = lower_bound(atdepth[d].begin(), atdepth[d].end(), lo);
        auto idx2 = lower_bound(atdepth[d].begin(), atdepth[d].end(), hi);

        // Print their distance
        cout << distance(idx1, idx2)-1 << " ";
    }
    cout << endl;

    return 0;
}

