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





int find(vector<int>& d, int a) {
    if(d[a] < 0) {
        return a;
    }

    d[a] = find(d, d[a]);
    return d[a];
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);

    if(a == b) {
        return;
    }

    d[a] += d[b];
    d[b] = a;
}

int size(vector<int>& d, int a) {
    a = find(d, a);
    return -d[a];
}

int main() {
    //file();
    fast();

    int n, m;
    cin >> n >> m;

    vector<uset<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;
        adj[n1].insert(n2);
        adj[n2].insert(n1);
    }

    vector<pair<int,int>> sortme;
    for(int i = 0; i < n; i++) {
        sortme.pb({adj[i].size(), i});
    }
    sort(rall(sortme));

    vector<int> d(n, -1);
    vector<bool> vis(n, false);
    for(auto& thing : sortme) {
        int i = thing.second;
        if(vis[i]) {
            continue;
        }
        vis[i] = true;

        for(int j = 0; j < n; j++) {
            if(i == j) {
                continue;
            }
            if(adj[i].count(j) == 0) {
                vis[j] = true;
                join(d, i, j);
            }
        }
    }

    vector<int> sizes;
    for(int i = 0; i < n; i++) {
        if(d[i] < 0) {
            sizes.pb(-d[i]);
        }
    }

    /*
    for(auto& i : d) {
        cout << i << " ";
    }
    cout << endl;
    */

    sort(all(sizes));
    cout << sizes.size() << endl;
    for(auto i : sizes) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
