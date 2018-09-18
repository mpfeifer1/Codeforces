#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct edge {
    int n1, n2, w;
};

int scc = 0;

// Calculates how many shrooms you can get from an edge total
ll calc(int n) {
    int st = 1, en = 17000, mi, rv = 0;
    while(st <= en) {
        mi = (st + en) >> 1;
        if(((mi * (mi+1)) >> 1) <= n) {
            rv = mi;
            st = mi + 1;
        }
        else {
            en = mi - 1;
        }
    }

    return (rv + 1) * (ll)n - rv * ((ll)rv + 1) * (rv + 2) / 6ll;
}

void dfs1(vector<pair<int,int>>* adj, bool* vis, stack<int>& r, int curr) {
    vis[curr] = true;
    for(auto& i : adj[curr]) {
        if(!vis[i.first]) {
            vis[i.first] = true;
            dfs1(adj, vis, r, i.first);
        }
    }

    r.push(curr);
}

void dfs2(vector<pair<int,int>>* adj, bool* vis, stack<int>& r, int* sccid, int scc, int curr) {
    sccid[curr] = scc;
    vis[curr] = true;
    for(auto& i : adj[curr]) {
        if(!vis[i.first]) {
            dfs2(adj, vis, r, sccid, scc, i.first);
        }
    }
}

vector<ll> memo;
ll dfs(bool* visi, vector<pair<int,int>>* metagraph_adj, ll* metagraph_w, int curr) {
    ll best = 0;
    visi[curr] = true;
    for(auto i : metagraph_adj[curr]) {
        int next = i.first;
        int weight = i.second;
        if(!visi[next]) {
            dfs(visi, metagraph_adj, metagraph_w, next);
        }
        best = max(best, (ll)weight + memo[i.first]);
    }

    memo[curr] = best + metagraph_w[curr];
    return memo[curr];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    // Build graph
    vector<pair<int,int>> adj1[n];
    vector<pair<int,int>> adj2[n];

    edge edges[m];

    for(int i = 0; i < m; i++) {
        int n1, n2, w;
        cin >> n1 >> n2 >> w;

        n1--;
        n2--;

        edges[i] = {n1, n2, w};
        adj1[n1].push_back({n2, w});
        adj2[n2].push_back({n1, w});
    }

    // First pass
    bool vis[n];
    memset(vis, false, n);
    stack<int> recent;
    for(int i = 0; i < n; i++) {
        if(vis[i]) {
            continue;
        }

        dfs1(adj1, vis, recent, i);
    }

    // Second pass
    int sccid[n];
    memset(vis, false, n);
    while(!recent.empty()) {
        int curr = recent.top();
        recent.pop();

        if(vis[curr]) {
            continue;
        }

        dfs2(adj2, vis, recent, sccid, scc, curr);
        scc++;
    }

    // Set up degree
    int degree[scc];
    for(auto& i : degree) {
        i = 0;
    }

    // Set up metagraph
    vector<pair<int,int>> metagraph_adj[scc];
    ll metagraph_w[scc];
    for(int i = 0; i < scc; i++) {
        metagraph_adj[i] = {};
        metagraph_w[i] = 0;
    }

    // Build metagraph
    for(auto& i : edges) {
        int curr = sccid[i.n1];
        int next = sccid[i.n2];
        if(curr == next) {
            metagraph_w[curr] += calc(i.w);
        }
        else {
            metagraph_adj[curr].push_back({next, i.w});
            degree[next]++;
        }
    }

    // Toposort to remove all degree 0 that aren't start
    int start;
    cin >> start;
    start = sccid[start-1];

    // Print answer
    bool visi[scc];
    for(int i = 0; i < scc; i++) {
        visi[i] = false;
    }
    memo.resize(scc, 0);
    cout << dfs(visi, metagraph_adj, metagraph_w, start) << endl;
}
