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





struct creature {
    ll hp;
    ll dmg;
};

ll gain(creature a) {
    return max(0ll, a.hp - a.dmg);
}

bool cmp(creature c1, creature c2) {
    return gain(c1) > gain(c2);
}

int main() {
    //file();
    fast();

    ll n, a, b;
    cin >> n >> a >> b;

    vector<creature> v(n);
    for(auto& i : v) {
        cin >> i.hp >> i.dmg;
    }

    sort(all(v), cmp);

    ll plain = 0;
    for(int i = 0; i < n; i++) {
        plain += v[i].dmg;
        if(i < b) {
            plain += gain(v[i]);
        }
    }

    ll ans = plain;
    if(b > 0) {
        for(int i = 0; i < n; i++) {
            ll candidate = plain;

            candidate -= v[i].dmg;
            if(i < b) {
                candidate -= gain(v[i]);
            }
            else {
                candidate -= gain(v[b-1]);
            }

            candidate += v[i].hp << a;

            ans = max(ans, candidate);
        }
    }

    cout << ans << endl;

    return 0;
}
