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





struct node {
    int val, l, r;
};

unordered_set<int> seen;

void dfs(vector<node>& v, int curr, int lo, int hi) {
    if(v[curr].val > lo && v[curr].val < hi) {
        seen.insert(v[curr].val);
    }

    if(v[curr].l >= 0) {
        int next = v[curr].l;
        dfs(v, next, lo, min(hi,v[curr].val));
    }
    if(v[curr].r >= 0) {
        int next = v[curr].r;
        dfs(v, next, max(lo,v[curr].val), hi);
    }
}

int main() {
    //file();
    fast();

    int n;
    cin >> n;

    vector<node> v(n);
    vector<int> deg(n, 0);

    unordered_map<int,int> vals;

    for(auto& i : v) {
        cin >> i.val >> i.l >> i.r;
        i.l--;
        i.r--;

        vals[i.val]++;

        if(i.l >= 0) {
            deg[i.l]++;
        }
        if(i.r >= 0) {
            deg[i.r]++;
        }
    }

    int start = -1;
    for(int i = 0; i < n; i++) {
        if(deg[i] == 0) {
            start = i;
        }
    }

    dfs(v, start, -iinf, iinf);

    // Calculate total
    for(auto i : seen) {
        vals.erase(i);
    }
    int total = 0;
    for(auto i : vals) {
        total += i.second;
    }

    cout << total << endl;
}
