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





struct edge {
    int n1, n2, w;
};

bool cmp(edge& e1, edge& e2) {
    return e1.w < e2.w;
}

int main() {
    //file();
    fast();

    int n, m;
    cin >> n >> m;
    vector<int> v(n, 0);

    // Sort edges
    vector<edge> edges(m);
    for(auto& i : edges) {
        cin >> i.n1 >> i.n2 >> i.w;
        i.n1--; i.n2--;
    }
    sort(all(edges), cmp);

    // Process graph
    umap<int,int> seen;
    for(int i = 0; i < edges.size(); i++) {
        // Grab current
        int curr = edges[i].n1;
        int next = edges[i].n2;

        // If on same edge weight
        if(i >= 1 && edges[i-1].w == edges[i].w) {
            int prev = v[curr];
            if(seen.count(curr) > 0) {
                prev = seen[curr];
            }

            if(seen.count(next) == 0) {
                seen[next] = v[next];
            }

            v[next] = max(prev+1, v[next]);
        }

        // If new edge weight
        else {
            seen.clear();
            seen[next] = v[next];
            v[next] = max(v[curr]+1, v[next]);
        }
    }

    // Find best
    int best = 0;
    for(auto& i : v) {
        best = max(best, i);
    }
    cout << best << endl;

    return 0;
}
