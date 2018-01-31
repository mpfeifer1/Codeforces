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




    int n, m;

bool iscyclic(vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& rec, int curr) {
    if(!vis[curr]) {
        vis[curr] = true;
        rec[curr] = true;

        for(auto next : adj[curr]) {
            if(!vis[next] && iscyclic(adj, vis, rec, next)) {
                return true;
            }
            else if(rec[next]) {
                return true;
            }
        }
    }

    rec[curr] = false;
    return false;
}

bool cycle(vector<vector<int>>& adj) {
    vector<bool> vis(n, false);
    vector<bool> rec(n, false);
    for(int i = 0; i < n; i++) {
        if(iscyclic(adj, vis, rec, i)) {
            return true;
        }
    }
    return false;
}

int main() {
    //file();
    //fast();

    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<vector<int>> count;
    count.resize(n, vector<int>(26, 0));

    vector<int> val(n);
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        val[i] = c - 'a';
    }

    vector<int> deg(n, 0);
    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;

        if(n1 == n2) {
            cout << "-1" << endl;
            return 0;
        }

        adj[n1].pb(n2);
        deg[n2]++;
    }

    if(cycle(adj)) {
        cout << "-1" << endl;
        return 0;
    }

    queue<int> zeroin;
    for(int i = 0; i < n; i++) {
        if(deg[i] == 0) {
            zeroin.push(i);
        }
    }

    int best = 0;
    while(!zeroin.empty()) {
        int curr = zeroin.front();
        zeroin.pop();

        count[curr][val[curr]]++;
        for(int i = 0; i < 26; i++) {
            best = max(best, count[curr][i]);
        }

        for(auto i : adj[curr]) {
            for(int j = 0; j < 26; j++) {
                count[i][j] = max(count[i][j], count[curr][j]);
            }
            deg[i]--;
            if(deg[i] == 0) {
                zeroin.push(i);
            }
        }
    }

    cout << best << endl;

    return 0;
}
