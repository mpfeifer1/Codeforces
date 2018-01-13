// Michael Pfeifer
// Version 02, 2018/01/12

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
#define debug(x) cout<<#x<<" -> "<<x<<'\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)

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
    auto b =  freopen("a.out", "w", stdout);
    if(!a || !b) cout << "uh oh" << endl;
}





int main() {
    //file();
    fast();

    int n;
    cin >> n;

    vector<ll> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    vector<string> s(n);
    for(auto& i : s) {
        cin >> i;
    }

    pair<ll,ll> big = {inf,inf};
    vector<pair<ll,ll>> cost(n, big);
    cost[0] = {0,v[0]};

    for(int i = 1; i < n; i++) {
        string s1, s2, r1, r2;
        r1 = s1 = s[i-1];
        r2 = s2 = s[i];
        reverse(all(r1));
        reverse(all(r2));

        if(s1 <= s2 && cost[i-1].first != inf) {
            cost[i].first = min(cost[i].first, cost[i-1].first);
        }
        if(r1 <= s2 && cost[i-1].second != inf) {
            cost[i].first = min(cost[i].first, cost[i-1].second);
        }
        if(s1 <= r2 && cost[i-1].first != inf) {
            cost[i].second = min(cost[i].second, cost[i-1].first + v[i]);
        }
        if(r1 <= r2 && cost[i-1].second != inf) {
            cost[i].second = min(cost[i].second, cost[i-1].second + v[i]);
        }

        if(cost[i] == big) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << min(cost[n-1].first, cost[n-1].second) << endl;
}
