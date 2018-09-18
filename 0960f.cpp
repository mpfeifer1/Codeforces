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

    // Each node stores the best val for each weight
    vector<map<int,int, greater<int>>> vis(n+1);
    for(auto& i : vis) {
        i[-1] = 0;
    }

    int best = 0;
    for(int i = 0; i < m; i++) {
        int n1, n2, w;
        cin >> n1 >> n2 >> w;

        int mostlen = vis[n1].upper_bound(w)->second + 1;
        best = max(best, mostlen);

        if(vis[n2].lower_bound(w)->second < mostlen) {
            vis[n2][w] = mostlen;
            auto it = vis[n2].find(w);
            while(it != vis[n2].begin() && prev(it)->second <= mostlen) {
                vis[n2].erase(prev(it));
            }
        }
    }

    /*
    for(int i = 1; i <= n; i++) {
        cout << "node " << i << endl;
        for(auto j : vis[i]) {
            cout << j.first << " " << j.second << endl;
        }
    }
    */

    cout << best << endl;

    return 0;
}
