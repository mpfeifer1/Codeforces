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





int main() {
    //file();
    //fast();

    ll n;
    cin >> n;

    vector<ll> pilesizes(n);
    for(auto& i : pilesizes) {
        cin >> i;
    }

    vector<ll> melt(n);
    for(auto& i : melt) {
        cin >> i;
    }

    vector<ll> totalmelt(n+1, 0);
    totalmelt[0] = 0;
    for(ll i = 0; i < n; i++) {
        totalmelt[i+1] = melt[i] + totalmelt[i];
    }

    vector<ll> completelymelted(n+1,0);
    vector<ll> partiallymelted(n+1,0);

    set<ll> piles;
    for(ll i = 0; i < n; i++) {
        ll lo = 1;
        ll hi = n+1;
        while(hi-lo>1) {
            ll mid = (hi+lo)/2;
            ll target = pilesizes[i];
            ll val = totalmelt[mid] - totalmelt[i];
            if(target >= val) {
                lo = mid;
            }
            else {
                hi = mid;
            }
        }

        while(pilesizes[i] - (totalmelt[lo]-totalmelt[i]) < 0) {
            lo--;
        }

        completelymelted[i]++;
        completelymelted[lo]--;

        partiallymelted[lo] += pilesizes[i] - (totalmelt[lo] - totalmelt[i]);
    }

    /*
    for(ll i = 0; i < n; i++) {
        cout << completelymelted[i] << " ";
    }
    cout << endl;
    for(ll i = 0; i < n; i++) {
        cout << partiallymelted[i] << " ";
    }
    cout << endl;
    */

    ll val = 0;
    for(ll i = 0; i < n; i++) {
        val += completelymelted[i];
        cout << val*melt[i] + partiallymelted[i] << " ";
    }
    cout << endl;

    return 0;
}
