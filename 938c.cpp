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





int diff(int l, int r) {
    return abs(l-r);
}

int calc(int l, int r) {
    if(r == 0 || l == 0) {
        return -iinf;
    }
    return (l*l) - ((l/r)*(l/r));
}

bool enough(int l, int r, int t) {
    if(r == 0 || l == 0) {
        return false;
    }

    return ((l*l) - ((l/r)*(l/r))) >= t;
}

int main() {
    //file();
    fast();

    int n;
    cin >> n;

    while(n--) {
        int t;
        cin >> t;

        bool printed = false;
        for(int i = 1; i*i <= t*10; i++) {
            int lo = 1;
            int hi = i;

            while(hi - lo > 0) {
                int mi = (hi+lo) / 2;
                if(enough(i, mi, t)) {
                    hi = mi;
                }
                else {
                    lo = mi + 1;
                }
            }

            if(calc(i, lo) == t) {
                printed = true;
                cout << i << " " << lo << endl;
                break;
            }
        }

        if(!printed) {
            if(t == 0) {
                cout << "1 1" << endl;
            }
            else {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}
