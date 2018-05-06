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





bool match(int curr, vector<vector<int>>& adj, vector<int>& l, vector<int>& r, vector<int>& vis) {
    if(vis[curr]) return false;
    vis[curr] = true;

    for(auto next : adj[curr]) {
        if(r[next] == -1 || match(r[next], adj, l, r, vis)) {
            l[curr] = next;
            r[next] = curr;
            return true;
        }
    }
    return false;
}

int bipartite(vector<vector<int>>& adj, int n, int m) {
    vector<int> l, r, vis;
    l.resize(n, -1);
    r.resize(m, -1);
    vis.resize(n);

    bool works = true;
    while(works) {
        works = false;
        fill(vis.begin(), vis.end(), 0);
        for(int i = 0; i < n; i++) {
            if(l[i] == -1) {
                works |= match(i, adj, l, r, vis);
            }
        }
    }

    int ret = 0;
    for(int i = 0; i < n; i++) {
        ret += (l[i] != -1);
    }
    return ret;
}

vector<int> factors(int n) {
    vector<int> ret;
    for(int i = 2; i <= sqrt(n); i++) {
        while(n % i == 0) {
            ret.pb(i);
            n /= i;
        }
    }
    if(n > 1) {
        ret.pb(n);
    }
    return ret;
}

int main() {
    //file();
    //fast();

    int n, m;
    cin >> n >> m;

    vector<int> e;
    vector<int> o;

    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if(i % 2 == 0) {
            e.pb(t);
        }
        else {
            o.pb(t);
        }
    }

    set<pair<int,int>> s;
    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        if(n1 % 2 == 0) {
            swap(n1,n2);
        }

        n1--;
        n2--;

        n1 /= 2;
        n2 /= 2;

        s.insert({n1,n2});
    }

    vector<pair<int,int>> l;
    vector<pair<int,int>> r;

    for(int i = 0; i < e.size(); i++) {
        vector<int> fac = factors(e[i]);
        for(auto j : fac) {
            l.pb({j,i});
        }
    }

    for(int i = 0; i < o.size(); i++) {
        vector<int> fac = factors(o[i]);
        for(auto j : fac) {
            r.pb({j,i});
        }
    }

    vector<vector<int>> adj(l.size());
    for(int i = 0; i < l.size(); i++) {
        for(int j = 0; j < r.size(); j++) {
            if(l[i].first == r[j].first) {
                if(s.count({l[i].second, r[j].second}) > 0) {
                    adj[i].pb(j);
                }
            }
        }
    }

    cout << bipartite(adj, l.size(), r.size()) << endl;

    return 0;
}
