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





int main() {
    //file();
    //fast();

    int n, m;
    cin >> n >> m;

    vector<int> color(n);
    for(auto& i : color) {
        cin >> i;
    }

    vector<int> deg(n, 0);
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].pb(n2);
        deg[n2]++;
    }

    // Loop through to grab zero-indegree
    queue<int> w, b;
    for(int i = 0; i < n; i++) {
        if(deg[i] == 0) {
            if(color[i] == 0) {
                w.push(i);
            }
            else {
                b.push(i);
            }
        }
    }

    int calls = 0;
    while(!w.empty() || !b.empty()) {
        // If serial tasks
        if(!w.empty()) {
            while(!w.empty()) {
                int curr = w.front();
                w.pop();

                for(auto i : adj[curr]) {
                    deg[i]--;
                    if(deg[i] == 0) {
                        if(color[i] == 0) {
                            w.push(i);
                        }
                        else {
                            b.push(i);
                        }
                    }
                }
            }
        }

        // Otherwise, sequential tasks
        else {
            calls++;
            while(!b.empty()) {
                int curr = b.front();
                b.pop();

                for(auto i : adj[curr]) {
                    deg[i]--;
                    if(deg[i] == 0) {
                        if(color[i] == 0) {
                            w.push(i);
                        }
                        else {
                            b.push(i);
                        }
                    }
                }
            }
        }
    }

    cout << calls << endl;
}
