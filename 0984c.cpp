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





set<ll> factors(ll n) {
    set<ll> ret;
    for(ll i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            ret.insert(i);
            while(n % i == 0) {
                n /= i;
            }
        }
    }
    if(n > 1) ret.insert(n);
    return ret;
}

bool finite() {
    ll p, q, b;
    cin >> p >> q >> b;

    ll gcd = __gcd(p,q);
    p /= gcd;
    q /= gcd;

    if(b == 1) return true;

    ll common = __gcd(q,b);
    set<ll> f = factors(common);
    for(auto i : f) {
        while(q % i == 0) {
            q /= i;
        }
        while(b % i == 0) {
            b /= i;
        }
    }

    if(q > 1) return false;

    return true;
}

int main() {
    //file();
    fast();

    int n;
    cin >> n;

    while(n--) {
        if(finite()) {
            cout << "Finite" << endl;
        }
        else {
            cout << "Infinite" << endl;
        }
    }

    return 0;
}
