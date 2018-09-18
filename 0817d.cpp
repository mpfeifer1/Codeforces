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





ll calc(vector<int>& v) {
    int n = v.size();

    vector<int> loidx(n);
    stack<int> lostack;
    for(int i = 0; i < n; i++) {
        while(lostack.size() > 0 && v[lostack.top()] <= v[i]) {
            lostack.pop();
        }

        if(lostack.size() == 0) {
            loidx[i] = -1;
        }
        else {
            loidx[i] = lostack.top();
        }

        lostack.push(i);
    }

    vector<int> hiidx(n);
    stack<int> histack;
    for(int i = n-1; i >= 0; i--) {
        while(histack.size() > 0 && v[histack.top()] < v[i]) {
            histack.pop();
        }

        if(histack.size() == 0) {
            hiidx[i] = n;
        }
        else {
            hiidx[i] = histack.top();
        }

        histack.push(i);
    }


    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll waysleft = hiidx[i] - i;
        ll waysright = i - loidx[i];
        ll val = waysleft * waysright * (ll)abs(v[i]);
        ans += val;
    }

    return ans;
}

int main() {
    //file();
    fast();

    int n;
    cin >> n;

    vector<int> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    ll ans = 0;
    ans += calc(v);
    for(auto& i : v) i *= -1;
    ans -= calc(v);
    cout << ans << endl;

    return 0;
}
