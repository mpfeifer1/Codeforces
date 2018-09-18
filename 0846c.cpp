// Michael Pfeifer
// Version 01, 2018/01/12

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
const int iinf = 2147483647;
const ll  inf  = 9223372036854775807ll;
const int mod  = 1000000007;

#define endl '\n'
#define pb push_back
#define D(x) cout<<#x<<" -> "<<x<<'\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)

template<class TIn>
using indexed_set = tree<
        TIn, null_type, less<TIn>,
        rb_tree_tag, tree_order_statistics_node_update>;





int main() {
    ll n;
    cin >> n;

    ll v[n];
    rep(i, n) {
        cin >> v[i];
    }

    // Run Kadane's to get midpoint
    ll curr = 0;
    ll best = 0;
    ll bestidx = 0;
    rep(i, n) {
        curr += v[i];
        if(curr > best) {
            best = curr;
            bestidx = i+1;
        }
    }

    ll idx1 = 0;
    ll idx2 = 0;
    bool side = false; // left

    // Run N^2 on left side
    ll overall_min = 0;
    for(ll i = 0; i < bestidx; i++) {
        ll curr = 0;
        for(ll j = i; j < bestidx; j++) {
            curr += v[j];
            if(curr < overall_min) {
                side = false;
                overall_min = curr;
                idx1 = i;
                idx2 = j+1;
            }
        }
    }

    // Run N^2 on right side
    ll overall_max = 0;
    for(ll i = bestidx; i < n; i++) {
        ll curr = 0;
        for(ll j = i; j < n; j++) {
            curr += v[j];
            // If locally better, set
            if(curr > overall_max) {
                overall_max = curr;
                // If totally better, flip
                if(overall_max > -overall_min) {
                    side = true;
                    idx1 = i;
                    idx2 = j+1;
                }
            }
        }
    }

    if(!side) {
        cout << idx1 << " " << idx2 << " " << bestidx << endl;
    }
    else {
        cout << bestidx << " " << idx1 << " " << idx2 << endl;
    }
}
