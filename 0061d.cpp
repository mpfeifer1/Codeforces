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





vector<ll> cost;
vector<ll> skip;
vector<bool> vis;
vector<vector<pair<ll,ll>>> adj;

void dfs(ll curr) {
    if(vis[curr]) return;
    vis[curr] = true;

    ll costhere = 0;
    ll bestskip = 0;
    for(auto i : adj[curr]) {
        ll next = i.first;
        ll weight = i.second;

        if(vis[next]) continue;

        dfs(next);
        costhere += (2 * weight) + cost[next];
        bestskip = max(bestskip, (cost[next]-skip[next])+weight);
    }

    cost[curr] = costhere;
    skip[curr] = costhere - bestskip;
}

int main() {
    //file();
    fast();

    ll n;
    cin >> n;

    cost.resize(n, 0);
    skip.resize(n, 0);
    vis.resize(n, false);
    adj.resize(n);

    for(ll i = 0; i < n-1; i++) {
        ll n1, n2, w;
        cin >> n1 >> n2 >> w;
        n1--; n2--;
        adj[n1].pb({n2,w});
        adj[n2].pb({n1,w});
    }

    dfs(0);
    cout << skip[0] << endl;

    return 0;
}
