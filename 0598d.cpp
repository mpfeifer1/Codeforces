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





int n, m, k;

int dfs(vector<vector<char>>& v, vector<vector<bool>>& vis, int i, int j) {
    if(vis[i][j] || v[i][j] == '*') {
        return 0;
    }
    vis[i][j] = true;

    int val = 0;
    if(v[i][j-1] == '*') {
        val++;
    }
    if(v[i][j+1] == '*') {
        val++;
    }
    if(v[i-1][j] == '*') {
        val++;
    }
    if(v[i+1][j] == '*') {
        val++;
    }

    val += dfs(v, vis, i+1, j);
    val += dfs(v, vis, i-1, j);
    val += dfs(v, vis, i, j+1);
    val += dfs(v, vis, i, j-1);

    return val;
}

int find(vector<int>& d, int a) {
    if(d[a] < 0) {
        return a;
    }
    return d[a] = find(d, d[a]);
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);

    if(a == b) {
        return;
    }

    d[a] = b;
}

int main() {
    //file();
    //fast();

    cin >> n >> m >> k;

    // Read in input
    vector<vector<char>> v;
    v.resize(n, vector<char>(m));
    for(auto& i : v) {
        for(auto& j : i) {
            cin >> j;
        }
    }

    // Create disjoint set
    vector<int> d(n*m, -1);

    // Do a pass with a disjoint set
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            int here = i*m+j;
            int left = i*m+(j-1);
            int up = (i-1)*m+j;
            if(v[i][j] == '.') {
                if(v[i-1][j] == '.') {
                    join(d, here, up);
                }
                if(v[i][j-1] == '.') {
                    join(d, here, left);
                }
            }
        }
    }

    // Do a pass to set vals of all parents
    vector<vector<bool>> vis;
    vis.resize(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int here = i*m+j;
            if(v[i][j] == '.' && !vis[i][j]) {
                int val = dfs(v, vis, i, j);
                d[find(d,here)] = -val;
            }
        }
    }

    // Run queries
    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        int here = a*m+b;
        cout << -d[find(d,here)] << endl;
    }

    return 0;
}
