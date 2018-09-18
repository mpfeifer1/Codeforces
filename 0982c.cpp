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





// score then child
pair<int,int> dfs(vector<vector<int>>& adj, vector<int>& vis, int curr) {
    vis[curr] = true;

    int score = 0;
    int child = 1;

    for(auto next : adj[curr]) {
        if(vis[next]) continue;
        pair<int,int> p = dfs(adj, vis, next);
        score += p.first;
        child += p.second;
    }

    if(curr != 0 && child % 2 == 0) {
        score++;
    }

    return {score, child};
}

int main() {
    //file();
    //fast();

    int n;
    cin >> n;

    if(n % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }

    vector<vector<int>> adj(n);
    vector<int> vis(n, false);
    for(int i = 0; i < n-1; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;
        adj[n1].pb(n2);
        adj[n2].pb(n1);
    }

    pair<int,int> p = dfs(adj, vis, 0);
    cout << p.first << endl;

    return 0;
}
