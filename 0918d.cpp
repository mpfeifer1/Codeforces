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





int n, m;

int solve(vector<vector<pair<int,char>>>& adj, int dp[100][100][26], int i, int j, char c) {
    // If already know, use that
    if(dp[i][j][c-'a'] != -1) {
        return dp[i][j][c-'a'];
    }

    // For everything in the adjacency list,
    rep(k, adj[i].size()) {
        // If we can use the edge and Max needs that edge, Lucas wins
        if(adj[i][k].second >= c && solve(adj, dp, j, adj[i][k].first, adj[i][k].second) == 0) {
            return dp[i][j][c-'a'] = 1;
        }
    }

    // Otherwise Max wins
    return dp[i][j][c-'a'] = 0;
}

int main() {
    //file();
    fast();

    // Build Adjacency List
    cin >> n >> m;
    vector<vector<pair<int,char>>> adj(n);
    for(int i = 0; i < m; i++) {
        int n1, n2;
        char c;
        cin >> n1 >> n2 >> c;
        n1--; n2--;
        adj[n1].pb({n2,c});
    }

    // Set up DP array (if outdegree 0, Max wins, else unknown)
    int dp[100][100][26];
    rep(i, 100) {
        rep(j, 100) {
            rep(k, 26) {
                if(adj[i].size() == 0) {
                    dp[i][j][k] = 0;
                }
                else {
                    dp[i][j][k] = -1;
                }
            }
        }
    }

    // For each state, solve
    rep(i, n) {
        rep(j, n) {
            if(solve(adj, dp, i, j, 'a') == 1) {
                cout << "A";
            }
            else {
                cout << "B";
            }
        }
        cout << endl;
    }

    return 0;
}
