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




struct time {
    ll s, e;
    bool operator<(const time& rhs) const {
        return e < rhs.e;
    }
};


int main() {
    //file();
    fast();

    ll n, q;
    cin >> n >> q;

    map<int, int> days;
    ll workingdays = n;

    rep(i,q) {
        ll l, r;
        int type;
        cin >> l >> r >> type;

        // If no overlap, add in the segment
        auto it = days.lower_bound(l);
        if(it == days.end()) {
            if(type == 1) {
                workingdays -= (r-l+1);
                days[r] = l;
            }
            cout << workingdays << endl;
            continue;
        }

        // While complete overlap
        ll firstleft = it->second;
        while(it != days.end() && it->first < r) {
            workingdays += it->first - it->second + 1;
            days.erase(it);
            it = days.lower_bound(l);
        }

        // If removing working days
        if(type == 2) {
            if(firstleft < l) {
                workingdays -= (l-1-firstleft+1);
                days[l-1] = firstleft;
            }
            if(it != days.end() && it->second < r+1) {
                workingdays += r+1-it->second;
                it->second = r+1;
            }
        }

        // If adding
        if(type == 1) {
            if(it == days.end() || r < it->second) {
                workingdays -= r - min(firstleft, l) + 1;
                days[r] = min(firstleft, l);
            }
            else {
                workingdays -= it->second-1 - min(firstleft, l) + 1;
                it->second = min(firstleft, l);
            }
        }

        // Print
        cout << workingdays << endl;
    }
}
