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





struct seq {
    int idx;
    int val;
    int len;
};

struct cmp1 {
    bool operator() (const seq& lhs, const seq& rhs) {
        return lhs.idx < rhs.idx;
    }
};

struct cmp2 {
    bool operator() (const seq& lhs, const seq& rhs) {
        if(lhs.len == rhs.len) {
            return lhs.idx < rhs.idx;
        }
        return lhs.len > rhs.len;
    }
};

int main() {
    //file();
    fast();

    // Take in first number
    vector<seq> v;
    int n;
    cin >> n;

    // Create first sequence length 1
    int t;
    cin >> t;
    v.pb({1, t, 1});

    // Read in following elements
    for(int i = 1; i < n; i++) {
        // Merge into back element
        cin >> t;
        if(t == v.back().val) {
            v.back().len++;
        }
        // Create new element
        else {
            v.pb({v.back().idx+1, t, 1});
        }
    }

    // Create sets sorted on index and on length
    set<seq, cmp1> byidx;
    set<seq, cmp2> bylen;

    for(auto i : v) {
        byidx.insert(i);
        bylen.insert(i);
    }

    // Keep erasing and merging sequences
    int total = 0;
    while(!bylen.empty()) {
        // Grab first element
        total++;
        seq curr = *bylen.begin();

        // Grab first element from other set
        auto it = byidx.find(curr);

        // Grab next element
        auto hi = it;
        hi++;

        // If surrounding elements exist
        if(it != byidx.begin() && hi != byidx.end()) {
            // Grab previous element
            auto lo = it;
            lo--;

            // Get actual values for both elements
            seq s1 = *lo;
            seq s2 = *hi;

            // If surrounding elements can be merged
            if(s1.val == s2.val) {
                byidx.erase(s1);
                byidx.erase(s2);
                bylen.erase(s1);
                bylen.erase(s2);
                s1.len += s2.len;
                bylen.insert(s1);
                byidx.insert(s1);
            }
        }

        // Erase initial element
        byidx.erase(curr);
        bylen.erase(curr);
    }

    cout << total << endl;

    return 0;
}
