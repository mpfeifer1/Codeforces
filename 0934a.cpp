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


    ll n, m;
    cin >> n >> m;

    vector<ll> v1(n);
    vector<ll> v2(m);

    for(auto& i : v1) {
        cin >> i;
    }
    for(auto& i : v2) {
        cin >> i;
    }

    // Calculate value of each pair
    vector<vector<ll>> best;
    best.resize(n, vector<ll>(m,0));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            best[i][j] = v1[i] * v2[j];
        }
    }

    // For each of Tommy's picks
    vector<ll> bests;
    for(ll k = 0; k < n; k++) {

        // Figure out Banban's pick
        ll besthere = -inf;
        for(ll i = 0; i < n; i++) {
            if(i == k) {
                continue;
            }
            for(ll j = 0; j < m; j++) {
                besthere = max(besthere, best[i][j]);
            }
        }
        bests.pb(besthere);

    }

    sort(all(bests));
    cout << bests[0] << endl;

    return 0;
}
