// Michael Pfeifer
// Version 03, 2018/01/30

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

ll readint(){
    char r;
    bool start=false,neg=false;
    ll ret=0;
    while(true){
        r=getchar();
        if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
            continue;
        }
        if((r-'0'<0 || r-'0'>9) && r!='-' && start){
            break;
        }
        if(start)ret*=10;
        start=true;
        if(r=='-')neg=true;
        else ret+=r-'0';
    }
    if(!neg) return ret;
    else return -ret;
}






ll fastpow(ll base, ll exp, ll mod) {
    ll res = 1;
    while(exp > 0) {
        if((exp & 1) == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }

    return res % mod;
}

void dfs1(vector<vector<int>>& adj, vector<bool>& vis, stack<int>& s, int curr) {
    if(vis[curr]) {
        return;
    }
    vis[curr] = true;

    for(auto next : adj[curr]) {
        dfs1(adj, vis, s, next);
    }

    s.push(curr);
}

int dfs2(vector<vector<int>>& adj, vector<bool>& vis, int curr) {
    if(vis[curr]) {
        return 0;
    }
    vis[curr] = true;

    int size = 1;
    for(auto next : adj[curr]) {
        size += dfs2(adj, vis, next);
    }
    return size;
}

int main() {
    //file();
    fast();

    int n;
    cin >> n;

    vector<vector<int>> adj1(n);
    vector<vector<int>> adj2(n);
    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        t--;
        adj1[i].pb(t);
        adj2[t].pb(i);
    }

    vector<bool> vis(n, false);
    stack<int> s;
    for(int i = 0; i < n; i++) {
        if(vis[i]) {
            continue;
        }

        dfs1(adj1, vis, s, i);
    }

    vis.clear();
    vis.resize(n, false);
    vector<int> comps;
    while(!s.empty()) {
        int curr = s.top();
        s.pop();
        if(vis[curr]) {
            continue;
        }

        comps.pb(dfs2(adj2, vis, curr));
    }
    sort(all(comps));

    ll ways = 1;
    for(auto i : comps) {
        if(i == 1) {
            ways <<= 1;
            ways %= mod;
        }
        else {
            ways *= fastpow(2, i, mod) - 2;
            ways %= mod;
        }
    }

    cout << ways << endl;

    return 0;
}
