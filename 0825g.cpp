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





void dfs1(int curr, vector<vector<int>>& adj, vector<int>& prev, vector<int>& mins, int curr_min) {
    curr_min = min(curr_min, curr);
    mins[curr] = curr_min;
    for(auto next : adj[curr]) {
        if(prev[curr] != next) {
            prev[next] = curr;
            dfs1(next, adj, prev, mins, curr_min);
        }
    }
}

int main() {
    //file();
    fast();

    int n, m;
    cin >> n >> m;

    // Build Adjacency List
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n-1; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].pb(n2);
        adj[n2].pb(n1);
    }

    // Read in First Query, make Prev and Visited
    int globalmin = iinf;
    int last = 0;
    int firstt, firstq;
    cin >> firstt >> firstq;
    firstq = (firstq+last)%n + 1;

    vector<int> prev(n+1, -1);
    vector<int> mins(n+1, iinf);
    vector<bool> vis(n+1,false);

    prev[firstq] = -1;
    dfs1(firstq, adj, prev, mins, iinf);

    // Remaining Queries
    for(int i = 0; i < m-1; i++) {
        int type, query;
        cin >> type >> query;
        query = (query+last)%n + 1;

        if(type == 1) {
            while(!vis[query] && query != firstq) {
                globalmin = min(globalmin, query);
                vis[query] = true;
                query = prev[query];
            }
        }

        if(type == 2) {
            int ans = min(mins[query], globalmin);

            cout << ans << endl;
            last = ans;
        }
    }

}
