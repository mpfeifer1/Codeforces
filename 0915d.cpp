// Michael Pfeifer
// Version 02, 2018/01/12

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
pair<int,int> forbidden = {600,600};
vector<int> cycle;
int cycle_start = 0;

unordered_set<int> w, g, b;
unordered_map<int,int> nextc;

bool actual_dfs(vector<vector<int>>& adj, bool detect, int curr, int par) {
    // Move from w to g
    w.erase(curr);
    g.insert(curr);

    // For each neighbor
    for(auto neighbor : adj[curr]) {
        // If forbidden, skip
        if(forbidden.first == curr && forbidden.second == neighbor) {
            continue;
        }

        // If b, skip
        if(b.count(neighbor) > 0) {
            continue;
        }

        // If g, return true
        if(g.count(neighbor) > 0) {
            cycle_start = neighbor;
            return true;
        }

        // If detecting full cycle, set parent
        if(detect) {
            nextc[curr] = neighbor;
        }

        // If dfs, return true
        if(actual_dfs(adj, detect, neighbor, curr)) {
            return true;
        }
    }

    // Move from g to b
    g.erase(curr);
    b.insert(curr);
    return false;
}

// Return true if cycle
bool dfs(vector<vector<int>>& adj, bool detect) {
    // Empty all visited sets
    w.clear();
    g.clear();
    b.clear();

    // Set all to unvisited
    for(int i = 0; i < n; i++) {
        w.insert(i);
    }

    // Check if any contains a cycle
    for(int i = 0; i < n; i++) {
        // If white, DFS
        if(w.count(i) > 0) {
            if(actual_dfs(adj, detect, i, 600)) {
                // If we're detecting cycles, build cycle
                if(detect) {
                    int temp = cycle_start;
                    cycle.push_back(temp);
                    while(nextc.count(temp) > 0) {
                        temp = nextc[temp];
                        cycle.push_back(temp);
                    }
                    cycle.push_back(cycle.front());
                }

                return true;
            }
        }
    }

    // Return
    return false;
}

int main() {
    //file();
    fast();

    // Build graph
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--;
        n2--;
        adj[n1].pb(n2);
    }

    // Sort everything in adjacency list
    for(auto& i : adj) {
        sort(all(i));
    }

    // If no cycle, quit. This builds cycle
    if(!dfs(adj, true)) {
        cout << "YES" << endl;
        return 0;
    }

    // For every cycle edge, set forbidden
    for(int i = 1; i < cycle.size(); i++) {
        forbidden = {cycle[i-1], cycle[i]};

        // If no remaining cycle, print and quit
        if(!dfs(adj, false)) {
            cout << "YES" << endl;
            return 0;
        }
    }

    // There's 2 disconnected cycles
    cout << "NO" << endl;
    return 0;
}
