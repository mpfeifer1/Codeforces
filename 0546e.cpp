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
const ll  inf  = 1e18 + 10;
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

int main() {
    //file();
    fast();

    ll n, m;
    cin >> n >> m;

    // Read in soldiers
    vector<int> start(n);
    vector<int> end(n);
    for(auto& i : start) {
        cin >> i;
    }
    for(auto& i : end) {
        cin >> i;
    }

    // Count soldiers
    int soldiersstart = 0;
    int soldiersend = 0;
    for(auto& i : start) {
        soldiersstart += i;
    }
    for(auto& i : end) {
        soldiersend += i;
    }

    // Check it works
    if(soldiersstart != soldiersend) {
        cout << "NO" << endl;
        return 0;
    }

    // Set up original graph and residual graph
    vector<vector<ll>> og, rg;
    og.resize(SIZE, vector<ll>(SIZE, 0));
    rg.resize(SIZE, vector<ll>(SIZE, 0));

    // Add start, end, and self-loops
    for(ll i = 0; i < n; i++) {
        og[0][i+1] = start[i];
        rg[0][i+1] = start[i];

        og[i+1][i+101] = inf;
        rg[i+1][i+101] = inf;

        og[i+101][201] = end[i];
        rg[i+101][201] = end[i];
    }

    // Add edges
    for(ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;

        og[u][v+100] = inf;
        rg[u][v+100] = inf;

        og[v][u+100] = inf;
        rg[v][u+100] = inf;
    }

    // If works, dump out answer
    int flow = fulkerson(og,rg,0,201,202);
    if(soldiersend == flow) {
        cout << "YES" << endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << og[i+1][j+101] - rg[i+1][j+101] << " ";
            }
            cout << endl;
        }
    }

    // Print it doesn't work
    else {
        cout << "NO" << endl;
    }
}
