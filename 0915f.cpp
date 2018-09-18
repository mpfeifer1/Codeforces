// Michael Pfeifer
// Version 02, 2018/01/17

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






int n;

struct node {
    int idx, val;
};

bool cmp(node& n1, node& n2) {
    return n1.val < n2.val;
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

    d[a] += d[b];
    d[b] = a;
}

int size(vector<int>& d, int a) {
    a = find(d, a);
    return -d[a];
}

ll calc(vector<vector<int>>& adj, vector<node>& v, bool maximize) {
    ll sum = 0;

    vector<int> d(n, -1);
    vector<bool> visited(n, false);
    for(auto& curr : v) {
        // Add sizes of all new chunks
        vector<int> sizes;
        for(auto next : adj[curr.idx]) {
            if(visited[next]) {
                sizes.pb(size(d, next));
                join(d, curr.idx, next);
            }
        }

        // Calc total
        ll sumhere = 0;
        ll prefix = 0;
        for(auto size : sizes) {
            sumhere += size;
            sumhere += prefix * size;
            prefix += size;
        }
        sumhere++;
        sum += sumhere * curr.val;

        // Mark visited
        visited[curr.idx] = true;
    }

    return sum;
}

int main() {
    //file();
    fast();

    // Read in all values
    cin >> n;
    vector<node> v(n);
    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        v[i] = {i,t};
    }

    // Build adjacency list
    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;
        adj[n1].pb(n2);
        adj[n2].pb(n1);
    }

    // Calculate minimum paths
    sort(all(v), cmp);
    ll hi = calc(adj, v, false);

    // Calculate maximum paths
    reverse(all(v));
    ll lo = calc(adj, v, true);

    cout << hi-lo << endl;
}
