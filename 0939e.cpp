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





bool f(vector<ll>& total, vector<ll>& elem, int i, int hi) {
    return (hi + total[i-1] - i*elem[i]) <= 0;
}

int main() {
    //file();
    fast();

    ll n;
    cin >> n;

    vector<ll> elem;
    vector<ll> total;

    elem.pb(0);
    total.pb(0);

    ld bestavg = 0;
    for(ll i = 0; i < n; i++) {
        ll q; cin >> q;

        if(q == 1) {
            ll t;
            cin >> t;

            elem.pb(t);
            total.pb(total.back()+t);

            ll lo = 1;
            ll hi = elem.size()-1;
            while(hi-lo>1) {
                ll mid = (hi+lo)/2;
                if(f(total, elem, mid, elem.back())) {
                    hi = mid;
                }
                else {
                    lo = mid;
                }
            }

            ld last = elem.back();
            ld avg = ld(total[lo]+elem.back()) / ld(lo+1);
            ld val = last-avg;
            bestavg = max(val, bestavg);
        }

        if(q == 2) {
            cout << fixed;
            cout.precision(8);
            cout << bestavg << endl;
        }
    }

    return 0;
}
