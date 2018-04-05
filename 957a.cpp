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






vector<string> split(string& s) {
    vector<string> ret;
    ret.pb("");
    for(auto i : s) {
        if(i == '?') {
            ret.pb("");
        }
        else {
            ret.back().pb(i);
        }
    }
    return ret;
}

int main() {
    //file();
    //fast();

    int n;
    cin >> n;

    string s;
    cin >> s;

    for(int i = 1; i <= s.size(); i++) {
        if(s[i] == '?') {
            continue;
        }
        if(s[i-1] == s[i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    if(s.front() == '?' || s.back() == '?') {
        cout << "Yes" << endl;
        return 0;
    }

    int qs = 0;
    for(auto i : s) {
        if(i == '?') {
            qs++;
        }
        else {
            qs = 0;
        }
        if(qs == 2) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    vector<string> v = split(s);
    for(int i = 1; i < v.size(); i++) {
        if(v[i-1].back() == v[i].front()) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}
