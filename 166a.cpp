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





struct score {
    int solved;
    int penalty;

    bool operator==(const score& s) {
        return (s.solved == solved) && (s.penalty == penalty);
    }
};

bool cmp(score& s1, score& s2) {
    if(s1.solved == s2.solved) {
        return s1.penalty < s2.penalty;
    }
    return s1.solved > s2.solved;
}

int main() {
    //file();
    //fast();

    int n, k;
    cin >> n >> k;

    vector<score> v(n);
    for(auto& i : v) {
        cin >> i.solved >> i.penalty;
    }
    sort(all(v), cmp);

    int lo = 0;
    int hi = 0;
    score target = v[k-1];

    for(int i = 0; i < n; i++) {
        if(v[i] == target) {
            lo = i;
            break;
        }
    }

    for(int i = n-1; i >= 0; i--) {
        if(v[i] == target) {
            hi = i;
            break;
        }
    }

    cout << hi - lo + 1 << endl;

    return 0;
}
