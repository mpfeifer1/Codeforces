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
const int mod  = 998244353;
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





ll find(vector<ll>& d, ll a) {
    if(d[a] == -1) return a;
    return d[a] = find(d,d[a]);
}

void join(vector<ll>& d, ll a, ll b) {
    a = find(d,a);
    b = find(d,b);
    if(a == b) return;
    d[a] = b;
}

ll getways(vector<vector<ll>>& adj, vector<ll>& color, ll start) {
    ll n = adj.size();
    queue<ll> q;
    q.push(start);
    color[start] = 0;
    vector<ll> v(2,0);
    vector<bool> vis(n,false);
    while(!q.empty()) {
        ll curr = q.front();
        q.pop();
        if(vis[curr]) continue;
        vis[curr] = true;
        v[color[curr]]++;
        for(auto next : adj[curr]) {
            if(color[next] == -1) {
                color[next] = color[curr] ^ 1;
                q.push(next);
            }
            else {
                if(color[next] ^ color[curr] == 0) {
                    return 0;
                }
            }
        }
    }

    ll ways_o = 1;
    ll ways_e = 1;

    while(v[0]--) {
        ways_o <<= 1;
        ways_o %= mod;
    }

    while(v[1]--) {
        ways_e <<= 1;
        ways_e %= mod;
    }

    return (ways_o + ways_e) % mod;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> adj(n);
    vector<ll> d(n,-1);
    for(ll i = 0; i < m; i++) {
        ll n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;

        adj[n1].pb(n2);
        adj[n2].pb(n1);

        join(d,n1,n2);
    }

    ll ways = 1;
    vector<ll> color(n,-1);
    for(ll i = 0; i < n; i++) {
        if(d[i] == -1) {
            ways *= getways(adj,color,i);
            ways %= mod;
        }
    }

    cout << ways << endl;
}

int main() {
    //file();
    fast();

    ll cases;
    cin >> cases;

    while(cases--) {
        solve();
    }

    return 0;
}
