// Michael Pfeifer
// Version 04, 2018/02/17

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
const ld  prec = .000001;

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





struct seg {
    int start, end, idx;
};

bool cmp(seg s1, seg s2) {
    if(s1.start == s2.start) {
        if(s1.end == s2.end) return false;
        return s1.end > s2.end;
    }
    return s1.start < s2.start;
}

int main() {
    //file();
    //fast();

    int n;
    cin >> n;

    vector<seg> v;
    for(int i = 1; i <= n; i++) {
        seg s;
        cin >> s.start >> s.end;
        s.idx = i;
        v.pb(s);
    }

    sort(all(v), cmp);

    int maxend = -1;
    int maxidx = -1;

    for(auto i : v) {
        if(maxend >= i.end) {
            cout << i.idx << " " << maxidx << endl;
            return 0;
        }

        if(maxend < i.end) {
            maxend = i.end;
            maxidx = i.idx;
        }
    }

    cout << "-1 -1" << endl;

    return 0;
}
