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





struct edge {
    int n1, n2, w;
};

bool cmp(edge& e1, edge& e2) {
    return e1.w < e2.w;
}

int find(vector<int>& d, int a) {
    if(d[a] == -1) {
        return a;
    }
    return d[a] = find(d, d[a]);
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);

    if(a == b) return;

    d[a] = b;
}

int n;

void bfs(vector<vector<int>>& ans, vector<vector<pair<int,int>>> adj, int start) {
    vector<int> vis(n, iinf);

    queue<int> q;
    q.push(start);
    vis[start] = 0;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(auto i : adj[curr]) {
            int next = i.first;
            int weight = i.second;
            if(vis[next] == iinf) {
                q.push(next);
                vis[next] = vis[curr] + weight;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        ans[start][i] = vis[i];
    }
}

int main() {
    //file();
    fast();

    cin >> n;

    vector<vector<int>> v;
    v.resize(n, vector<int>(n));

    vector<edge> edges;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
            edges.pb({i,j,v[i][j]});
        }
    }

    bool works = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                if(v[i][j] != 0) {
                    works = false;
                }
            }

            else {
                if(v[i][j] != v[j][i]) {
                    works = false;
                }
                if(v[i][j] == 0) {
                    works = false;
                }
            }
        }
    }

    if(!works) {
        cout << "NO" << endl;
        return 0;
    }

    sort(all(edges), cmp);

    vector<vector<pair<int,int>>> adj(n);
    vector<int> d(n, -1);

    for(auto i : edges) {
        if(find(d,i.n1) != find(d,i.n2)) {
            join(d, i.n1, i.n2);
            adj[i.n1].pb({i.n2,i.w});
            adj[i.n2].pb({i.n1,i.w});
        }
    }

    vector<vector<int>> a;
    a.resize(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        bfs(a, adj, i);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(v[i][j] != a[i][j]) {
                works = false;
            }
        }
    }

    if(works) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }


    return 0;
}
