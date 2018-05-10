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





void del(vector<int>& par, vector<vector<int>>& son, vector<bool>& vis, vector<int>& size, int curr) {
    if(vis[curr]) return;
    vis[curr] = true;
    cout << curr+1 << endl;

    for(auto next : son[curr]) {
        del(par, son, vis, size, next);
    }
}

void dfs(vector<int>& par, vector<vector<int>>& son, vector<bool>& vis, vector<int>& size, int curr) {
    size[curr] = 1;

    for(auto next : son[curr]) {
        dfs(par, son, vis, size, next);
        size[curr] += size[next];
    }

    if(size[curr] % 2 == 0) {
        del(par, son, vis, size, curr);
    }
}

int main() {
    //file();
    fast();

    int n;
    cin >> n;

    if(n % 2 == 0) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    int root = 0;

    vector<int> par(n);
    vector<vector<int>> son(n);
    vector<bool> vis(n, false);
    vector<int> size(n);

    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        if(t == 0) {
            root = i;
        }
        else {
            t--;
            par[i] = t;
            son[t].pb(i);
        }
    }

    dfs(par, son, vis, size, root);
    del(par, son, vis, size, root);

    return 0;
}
