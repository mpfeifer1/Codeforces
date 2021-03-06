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





void getchildren(vector<vector<pair<int,int>>>& adj, vector<int>& child, int curr) {
    for(auto i : adj[curr]) {
        int next = i.first;
        getchildren(adj, child, next);
        child[curr] += 1 + child[next];
    }
}

void dfs(vector<vector<pair<int,int>>>& adj, vector<int>& val, vector<ll>& weight, vector<ll>& ways, vector<int>& path, int curr) {
    path.pb(curr);

    // Binary search to find the earliest who controls
    // find the node such that the weight there is <= the val here
    int target = val[curr];
    int lo = 0;
    int hi = path.size()-1;
    //cout << "Bounds are " << lo << " " << hi << endl;
    while(hi - lo > 0) {
        int mid = (hi+lo) / 2;
        if(weight[curr] - weight[path[mid]] <= target) {
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    if(lo > 0) {
        ways[path[lo-1]]++;
    }

    // DFS
    for(auto i : adj[curr]) {
        int next = i.first;
        int w = i.second;
        weight[next] = weight[curr] + w;
        dfs(adj, val, weight, ways, path, next);
    }

    // On way back, out keep track of ways
    for(auto i : adj[curr]) {
        int next = i.first;
        ways[curr] += ways[next];
    }

    /*
    if(adj[curr].size() == 0) {
        ways[curr] = 0;
    }
    else {
        int temp = adj[curr].size();
        for(auto i : adj[curr]) {
            temp += ways[i.first];
        }
        //temp -= ways[curr];
        ways[curr] = temp;
    }
    */

    path.pop_back();
}

int main() {
    //file();
    fast();

    int n;
    cin >> n;

    // Read in all node weights
    vector<int> val(n+1);
    val[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> val[i];
    }

    // Build Adjacency List
    vector<vector<pair<int,int>>> adj(n+1);
    adj[0].pb({1,0});
    for(int i = 2; i <= n; i++) {
        int n1, w;
        cin >> n1 >> w;
        adj[n1].pb({i,w});
    }

    // Check Adjacency List
    //for(int i = 0; i <= n; i++) {
    //    cout << i << ": ";
    //    for(auto j : adj[i]) {
    //        cout << j.first << " ";
    //    }
    //    cout << endl;
    //}

    // Run the DFS
    vector<ll> weight(n+1, 0);
    vector<ll> ways(n+1, 0);
    vector<int> path;
    vector<int> child(n+1, 0);

    dfs(adj, val, weight, ways, path, 1);
    getchildren(adj, child, 1);

    for(int i = 1; i <= n; i++) {
        cout << child[i] - ways[i] << " ";
    }
    cout << endl;

    return 0;
}
