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





int works(vector<int>& v, int keep, int target) {
    int kept = 0;
    for(auto& i : v) {
        if(i <= keep) {
            kept++;
        }
    }

    if(kept == target) {
        return 0;
    }

    if(kept < target) {
        return -1;
    }

    if(kept > target) {
        return 1;
    }
}

int main() {
    //file();
    //fast();

    int n, m;
    cin >> n >> m;

    map<int,int> cnt;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        cnt[t]++;
    }

    if(m == 0) {
        if(cnt.count(1) > 0) {
            cout << -1 << endl;
        }
        else {
            cout << 1 << endl;
        }
        return 0;
    }

    int total = 0;
    int val = 0;
    for(auto i : cnt) {
        if(total >= m) {
            break;
        }
        total += i.second;
        val = i.first;
    }

    if(total < m || total > m) {
        cout << -1 << endl;
    }
    else {
        if(val == 0) {
            cout << -1 << endl;
        }
        else {
            cout << val << endl;
        }
    }

    return 0;
}
