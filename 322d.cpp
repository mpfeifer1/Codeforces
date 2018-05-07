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





ll damage(vector<ll>& atk, vector<ll>& all, ll kills) {
    bool works = true;
    ll dmg = 0;

    for(ll i = 0; i < min(kills,(ll)all.size()); i++) {
        if(all[i] < atk[kills-i-1]) {
            works = false;
        }
        dmg += all[i] - atk[kills-i-1];
    }

    if(works) return dmg;
    else return 0;
}

ll attack(vector<ll> atk, vector<ll> all) {
    reverse(all(all));

    ll dmg = 0;
    for(ll kills = 1; kills <= atk.size(); kills++) {
        dmg = max(dmg, damage(atk, all, kills));
    }

    return dmg;
}

ll defense(vector<ll> atk, vector<ll> def, vector<ll> all) {
    if(atk.size() + def.size() >= all.size()) {
        return 0;
    }

    multiset<ll> all2;
    for(auto i : all) {
        all2.insert(i);
    }

    bool works = true;
    for(auto i : def) {
        auto next = all2.lower_bound(i+1);
        if(next == all2.end()) {
            works = false;
            break;
        }
        all2.erase(next);
    }
    vector<ll> all3;
    for(auto i : all2) {
        all3.pb(i);
    }

    sort(all(all3));
    sort(all(atk));

    reverse(all(all3));
    reverse(all(atk));

    ll dmg = 0;
    for(ll i = 0; i < all3.size(); i++) {
        if(i >= atk.size()) {
            dmg += all3[i];
            continue;
        }
        if(all3[i] < atk[i]) {
            works = false;
        }
        dmg += all3[i] - atk[i];
    }

    if(works) return dmg;
    else return 0;
}

int main() {
    //file();
    //fast();

    ll n, m;
    cin >> n >> m;

    vector<ll> atk;
    vector<ll> def;
    vector<ll> all;

    for(ll i = 0; i < n; i++) {
        string s;
        ll t;
        cin >> s >> t;
        if(s =="ATK") {
            atk.pb(t);
        }
        if(s == "DEF") {
            def.pb(t);
        }
    }

    for(ll i = 0; i < m; i++) {
        ll t;
        cin >> t;
        all.pb(t);
    }

    sort(all(atk));
    sort(all(def));
    sort(all(all));

    ll ans = 0;
    ans = max(ans, attack(atk, all));
    ans = max(ans, defense(atk, def, all));

    cout << ans << endl;

    return 0;
}
