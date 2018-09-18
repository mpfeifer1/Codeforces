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





void dfs_color(ll curr, vector<vector<ll>>& adj, vector<ll>& color, vector<bool>& vis, ll& ecount, ll& ocount, vector<ll>& echild, vector<ll>& ochild, ll currcolor) {
    if(vis[curr]) return;
    vis[curr] = true;

    // Set this node's color
    color[curr] = currcolor;
    if(currcolor == 0) ecount++;
    else ocount++;

    // Set children's color
    for(auto next : adj[curr]) {
        dfs_color(next, adj, color, vis, ecount, ocount, echild, ochild, currcolor ^ 1);
    }

    // Calculate evens and odds in this subtree
    ll ehere = 0;
    ll ohere = 0;
    if(currcolor == 0) ehere++;
    else ohere++;
    for(auto next : adj[curr]) {
        ehere += echild[next];
        ohere += ochild[next];
    }

    // Set the evens and odds for this subtree
    echild[curr] = ehere;
    ochild[curr] = ohere;
}

ll mul(ll a, ll b) {
    a = (a%mod+mod)%mod;
    b = (b%mod+mod)%mod;
    return (a*b) % mod;
}

ll add(ll a, ll b) {
    return (a+b) % mod;
}

void solve(ll curr, vector<vector<ll>>& adj, vector<bool>& vis, vector<ll>& color, ll ecount, ll ocount, vector<ll>& echild, vector<ll>& ochild, vector<ll>& ways) {
    if(vis[curr]) return;
    vis[curr] = true;

    for(auto next : adj[curr]) {
        solve(next, adj, vis, color, ecount, ocount, echild, ochild, ways);
    }

    ll eabove = ecount - echild[curr];
    ll oabove = ocount - ochild[curr];

    vector<ll> epaths;
    vector<ll> opaths;
    epaths.pb(eabove);
    opaths.pb(oabove);
    for(auto next : adj[curr]) {
        epaths.pb(echild[next]);
        opaths.pb(ochild[next]);
    }

    // If odd, treat it like it's even
    if(color[curr] == 1) {
        swap(epaths, opaths);
    }

    // Add path for itself
    epaths.pb(1);
    opaths.pb(0);

    // Calculate sums of even and odd
    ll esum = 0;
    ll osum = 0;
    for(auto i : epaths) esum += i;
    for(auto i : opaths) osum += i;

    // Add in even paths
    // Subtract out odd paths
    ll wayshere = 0;
    for(auto i : epaths) {
        wayshere += mul(i,(esum - i));
    }
    for(auto i : opaths) {
        wayshere -= mul(i,(osum - i));
    }
    ways[curr] = wayshere;
}

int main() {
    //file();
    fast();

    ll n;
    cin >> n;

    vector<ll> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    vector<vector<ll>> adj(n);
    vector<bool> isroot(n, true);
    for(ll i = 0; i < n-1; i++) {
        ll n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;
        adj[n1].pb(n2);
        isroot[n2] = false;
    }

    ll root = 0;
    for(ll i = 0; i < n; i++) {
        if(isroot[i]) root = i;
    }

    // mark all nodes even or odd initially
    // for each path away, calculate #even and #odd

    vector<ll> color(n);
    vector<bool> vis(n, false);
    ll ecount = 0;
    ll ocount = 0;
    vector<ll> echild(n, 0); // tells you how many 'e' here and below
    vector<ll> ochild(n, 0); // tells you how many 'o' here and below
    dfs_color(root, adj, color, vis, ecount, ocount, echild, ochild, 0);

    // do a dfs from root
    // base case: there's one path with all others above
    // general case: there's one path for each child with their vals, and one for parent (if any)
    // then, for each node, calculate the ways it will be in a path (+) and (-)

    vis.clear();
    vis.resize(n, false);
    vector<ll> ways(n, 0);

    solve(root, adj, vis, color, ecount, ocount, echild, ochild, ways);

    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        ans += mul(v[i], ways[i]);
        ans %= mod;
    }
    for(ll i = 0; i < n; i++) ans += v[i];
    cout << ((ans%mod)+mod)%mod << endl;

    return 0;
}
