// Michael Pfeifer
// Version 04, 2018/02/17

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ld  pi   = 4.0*atanl(1.0);
const int iinf = 1e9 + 10;
const ll  inf  = 1e18 + iinf + 10;
const int mod  = 1000000007;
const ld  prec = .000001;

#define enld endl
#define endl '\n'
#define pb push_back
#define debug(x) cout<<#x<<" -> "<<x<<'\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define umap unordered_map
#define uset unordered_set

template<class TIn>
using indexed_set = tree<
        TIn, null_type, less<TIn>,
        rb_tree_tag, tree_order_statistics_node_update>;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void file() {
    auto a = freopen("a.in",  "r", stdin);
    auto b = freopen("a.out", "w", stdout);
    if(!a || !b) cout << "uh oh" << endl;
}





const int SIZE = 202;

ll bfs(vector<vector<ll>>& og, vector<vector<ll>>& rg, vector<ll>& par, ll s, ll t, ll n) {
    vector<ll> f(SIZE, 0);

    vector<bool> visited(SIZE, false);
    visited[s] = true;

    queue<ll> q;
    q.push(s);
    par[s] = -1;
    f[s] = inf;

    while(!q.empty()) {
        ll u = q.front();
        q.pop();
        for(ll v = 0; v < n; v++) {
            if(visited[v] == false && rg[u][v] > 0) {
                q.push(v);
                par[v] = u;
                visited[v] = true;
                f[v] = min(f[u], rg[u][v]);
            }
        }
    }

    if(visited[t]) {
        return f[t];
    }
    return 0;
}

// Takes in original graph, residual graph, source, sink, #nodes
ll fulkerson(vector<vector<ll>>& og, vector<vector<ll>>& rg, ll s, ll t, ll n) {
    ll max_flow = 0, path_flow = 0;

    vector<ll> par(SIZE);

    while(path_flow = bfs(og, rg, par, s, t, n)) {
        for(ll v = t; v != s; v = par[v]) {
            ll u = par[v];
            rg[u][v] -= path_flow;
            rg[v][u] += path_flow;
        }
        max_flow += path_flow;
    }

    return max_flow;
}

void dfs(vector<vector<ll>>& adj, vector<bool>& vis, vector<int>& path, vector<ll>& v, int curr) {
    if(vis[curr]) {
        return;
    }
    vis[curr] = true;
    path.pb(curr);

    for(int next = 1; next <= 200; next++) {
        if(v[next] % 2 == 0 && adj[curr][next] == 1) {
            dfs(adj, vis, path, v, next);
        }
        if(v[next] % 2 == 1 && adj[next][curr] == 1) {
            dfs(adj, vis, path, v, next);
        }
    }
}

bool isprime(int n) {
    if(n < 2) return false;
    if(n == 2) return true;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    //file();
    //fast();

    ll n;
    cin >> n;

    ll s = 0;
    ll t = 201;

    vector<ll> v(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    // Set up original graph and residual graph
    vector<vector<ll>> og, rg;
    og.resize(SIZE, vector<ll>(SIZE, 0));
    rg.resize(SIZE, vector<ll>(SIZE, 0));

    int e = 0;
    int o = 0;

    // Connect Source and Sink
    for(int i = 1; i <= n; i++) {
        if(v[i] % 2 == 0) {
            e++;
            og[s][i] = 2;
        }
        else {
            o++;
            og[i][t] = 2;
        }
    }

    // Connect internally
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(v[i] % 2 == 0 && v[j] % 2 == 1) {
                if(isprime(v[i] + v[j])) {
                    og[i][j] = 1;
                }
            }
        }
    }

    // Copy original to residual
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            rg[i][j] = og[i][j];
        }
    }

    // Run flow
    int flow = fulkerson(og,rg,s,t,SIZE);

    // If it works, extract answer
    if(e == o && flow == n) {
        // DFS to find paths
        vector<bool> vis(n+1,false);
        vector<vector<int>> paths;
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) {
                vector<int> path;
                dfs(rg, vis, path, v, i);
                paths.pb(path);
            }
        }

        // Print all paths
        cout << paths.size() << endl;
        for(auto i : paths) {
            cout << i.size() << " ";
            for(auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    // It's impossible
    else {
        cout << "Impossible" << endl;
    }

    return 0;
}
