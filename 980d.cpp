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





bool square(ll n) {
    if(n < 0) return false;
    ll s = (ll)sqrtl(ld(n));
    return s*s == n;
}

ll find(ll d[5005], ll a) {
    if(d[a] == -1) return a;
    return d[a] = find(d, d[a]);
}

void join(ll d[5005], ll a, ll b) {
    a = find(d,a);
    b = find(d,b);
    if(a == b) return;
    d[a] = b;
}

int main() {
    //file();
    fast();

    ll n; cin >> n;
    ll v[5005];
    for(ll i = 0; i < n; i++) {
        cin >> v[i];
    }

    ll d[5005];
    for(ll i = 0; i < 5005; i++) {
        d[i] = -1;
    }

    for(ll i = 0; i < n; i++) {
        for(ll j = i+1; j < n; j++) {
            if(v[i] == 0 || v[j] == 0) continue;

            if(square(v[i] * v[j])) {
                join(d, i, j);
            }
        }
    }

    ll ans[5005];
    for(ll i = 0; i < 5005; i++) {
        ans[i] = 0;
    }

    for(ll i = 0; i < n; i++) {
        bool used[5005];
        for(ll j = 0; j < 5005; j++) {
            used[j] = false;
        }
        ll size = 0;
        bool z = false;

        for(ll j = i; j < n; j++) {
            if(v[j] == 0) {
                z = true;
            }
            else {
                if(!used[find(d,j)]) {
                    used[find(d,j)] = true;
                    size++;
                }
            }

            if(z) {
                ans[max(size, 1ll)]++;
            }
            else {
                ans[size]++;
            }

        }
    }

    for(ll i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
