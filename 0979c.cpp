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





// returns whether the paths has the endpoint in it
pair<bool,int> dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& in, int x, int y, int curr) {
    if(vis[curr]) return {true, 0};
    vis[curr] = true;

    int cnt = 1;
    bool good = true;
    for(auto next : adj[curr]) {
        if(next == y) {
            good = false;
            continue;
        }
        pair<bool,int> p = dfs(adj, vis, in, x, y, next);
        if(!p.first) good = false;
        else cnt += p.second;
    }

    return {good, cnt};
}

int main() {
    //file();
    //fast();

    int n, x, y;
    cin >> n >> x >> y;
    x--; y--;

    vector<vector<int>> adj(n);

    for(int i = 0; i < n-1; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;

        adj[n1].pb(n2);
        adj[n2].pb(n1);
    }

    ll good = (ll)n * (n-1);

    vector<bool> vis(n, false);
    vector<bool> in(n, false);

    ll g1 = dfs(adj, vis, in, x, y, x).second;

    vis.clear(); vis.resize(n, false);
    in.clear(); in.resize(n, false);
    ll g2 = dfs(adj, vis, in, y, x, y).second;

    cout << good - (g1 * g2) << endl;

    return 0;
}
