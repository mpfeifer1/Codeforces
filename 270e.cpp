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





int main() {
    //file();
    //fast();

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n+1);

    vector<int> in(n+1,0);
    vector<int> out(n+1,0);

    vector<pair<int,int>> input;
    for(int i = 0; i < m; i++) {
        int n1, n2, w;
        cin >> n1 >> n2 >> w;

        adj[n1].pb({n2,w});
        adj[n2].pb({n1,w});

        out[n1] += w;
        out[n2] += w;

        input.pb({n1,n2});
    }

    queue<int> zeroin;
    zeroin.push(1);
    vector<int> vis(n+1,false);
    vector<int> idx(n+1,0);

    int val = 1;
    while(!zeroin.empty()) {
        int curr = zeroin.front();
        zeroin.pop();

        vis[curr] = true;
        idx[curr] = val++;

        for(auto next : adj[curr]) {
            if(vis[next.first]) continue;

            out[next.first] -= next.second;
            in[next.first] += next.second;

            if(next.first != n && out[next.first] == in[next.first]) {
                zeroin.push(next.first);
            }
        }
    }
    idx[n] = val;

    for(auto i : input) {
        if(idx[i.first] < idx[i.second]) {
            cout << 0 << endl;
        }
        else {
            cout << 1 << endl;
        }
    }

    return 0;
}
