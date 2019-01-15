#include <bits/stdc++.h>

using namespace std;
typedef vector<vector<int>> graph;
typedef vector<pair<int,int>> vpii;
typedef vector<bool> vb;
typedef vector<int> vi;
int inf = 1 << 30;

int dfstime = 0;

void find(graph& adj, vpii& bridges, vb& vis, vi& par, vi& hi, vi& lo, int curr) {
    vis[curr] = true;
    hi[curr] = lo[curr] = ++dfstime;
    for(auto next : adj[curr]) {
        if(!vis[next]) {
            par[next] = curr;
            find(adj, bridges, vis, par, hi, lo, next);
            lo[curr] = min(lo[curr], lo[next]);
            if(lo[next] > hi[curr]) {
                bridges.push_back({next,curr});
            }
        }
        else if(next != par[curr]) {
            lo[curr] = min(lo[curr], hi[next]);
        }
    }
}

int dfs(graph& adj, vb& vis, set<pair<int,int>>& skip, int curr) {
    vis[curr] = true;
    int total = 1;
    for(auto next : adj[curr]) {
        if(vis[next]) {
            continue;
        }
        if(skip.count({curr,next}) || skip.count({next,curr})) {
            continue;
        }
        total += dfs(adj, vis, skip, next);
    }
    return total;
}

int find(vi& d, int a) {
    if(d[a] == -1) return a;
    return d[a] = find(d, d[a]);
}

void join(vi& d, int a, int b) {
    a = find(d,a);
    b = find(d,b);
    if(a == b) return;
    d[a] = b;
}

// returns {node,dist}
pair<int,int> getfarthest(vector<vector<int>>& adj, int start) {
    vector<int> dist(adj.size(),inf);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    int farthest_node = start;
    int farthest_dist = 0;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        farthest_node = curr;
        farthest_dist = dist[curr];

        for(auto next : adj[curr]) {
            if(dist[next] > dist[curr]+1) {
                dist[next] = dist[curr]+1;
                q.push(next);
            }
        }
    }

    return {farthest_node,farthest_dist};
}

int main() {
    int n, m;
    cin >> n >> m;

    // Read in graph
    graph adj(n);
    vpii edges;
    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
        edges.push_back({n1,n2});
    }

    // Allocate memory
    vpii bridges;
    vb vis(n,false);
    vi par(n,-1);
    vi hi(n,-1);
    vi lo(n,-1);

    // Find bridges
    find(adj, bridges, vis, par, hi, lo, 0);

    set<pair<int,int>> realbridges;
    for(auto i : bridges) {
        realbridges.insert(i);
    }

    // Join everything
    vi d(n, -1);
    for(auto i : edges) {
        if(realbridges.count(i)) continue;
        if(realbridges.count({i.second,i.first})) continue;
        join(d,i.first,i.second);
    }

    // Build adj using only bridges
    vector<vector<int>> newadj(n);
    for(auto i : bridges) {
        int n1 = find(d,i.first);
        int n2 = find(d,i.second);
        newadj[n1].push_back(n2);
        newadj[n2].push_back(n1);
    }

    if(bridges.size() > 0) {
        int start = find(d,bridges[0].first);
        start = getfarthest(newadj,start).first;
        cout << getfarthest(newadj,start).second << endl;
    }
    else {
        cout << 0 << endl;
    }

}
