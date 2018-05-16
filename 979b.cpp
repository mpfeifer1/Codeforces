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
const ll  inf  = 1e18 + iinf + 10;
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





int main() {
    //file();
    //fast();

    ll n;
    cin >> n;

    vector<ll> val(3);

    for(ll i = 0; i < 3; i++) {
        string s;
        cin >> s;

        if(s.size() == 1) {
            cout << "Draw" << endl;
            return 0;
        }

        ll ncpy = n;

        map<char,ll> m;
        for(auto j : s) {
            if(m.count(j) == 0) m[j] = 0;
            m[j]++;
        }

        ll good = 0;
        for(auto j : m) {
            if(j.second > good) {
                good = j.second;
            }
        }
        ll bad = s.size() - good;

        ll moves = min(ncpy, bad);
        good += moves;
        bad -= moves;
        ncpy -= moves;

        if(n == 1 && ncpy == 1) good--;

        val[i] = good;
    }

    ll best = max({val[0], val[1], val[2]});
    vector<ll> bestidx;
    for(ll i = 0; i < 3; i++) {
        if(val[i] == best) bestidx.pb(i);
    }

    if(bestidx.size() > 1) {
        cout << "Draw" << endl;
        return 0;
    }

    if(bestidx[0] == 0) {
        cout << "Kuro" << endl;
    }

    if(bestidx[0] == 1) {
        cout << "Shiro" << endl;
    }

    if(bestidx[0] == 2) {
        cout << "Katie" << endl;
    }

    return 0;
}
