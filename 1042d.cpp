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

    ll n, t;
    cin >> n >> t;

    ll total = 0;
    vector<ll> v(n+2,0), r(n+2,0),l(n+2,0);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        total += v[i];
    }

    for(int i = 1; i <= n+1; i++) {
        l[i] = l[i-1] + v[i];
    }
    for(int i = n; i >= 0; i--) {
        r[i] = r[i+1] + v[i];
    }

    indexed_set<pair<ll,ll>> sums;
    sums.insert({0,0});

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        auto it = sums.lower_bound({total - t - r[i+1] + 1, -1});
        ll inc;
        if(it == sums.end()) {
            inc = 0;
        }
        else {
            inc = i - sums.order_of_key(*it);
        }
        ans += inc;

        // Debugging print
        /*
        cout << "Looking for vals greater than " << total -  t - r[i+1] << endl;
        cout << "Dump sums" << endl;
        for(auto i : sums) {
            cout << i.first << " ";
        }
        cout << endl;
        cout << "Found " << (*it).first << endl;
        cout << "Added " << inc << endl;
        cout << endl << endl;
        */

        sums.insert({l[i], i});
    }

    cout << ans << endl;

    return 0;
}
