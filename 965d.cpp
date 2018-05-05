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





bool works(vector<int> rocks, int frogcount, int jumpsize) {
    if(frogcount == 0) {
        return true;
    }

    vector<int> frogs(rocks.size());
    frogs[0] = frogcount;

    int frogidx = 0;
    int rockidx = 1;

    while(true) {
        while(frogidx < frogs.size() && frogs[frogidx] == 0) {
            frogidx++;
        }
        while(rockidx < rocks.size() && rocks[rockidx] == 0) {
            rockidx++;
        }

        if(rockidx - frogidx > jumpsize) {
            return false;
        }

        if(rockidx >= rocks.size()) {
            return true;
        }

        int jumps = min(frogs[frogidx], rocks[rockidx]);

        frogs[frogidx] -= jumps;
        rocks[rockidx] -= jumps;

        frogs[rockidx] += jumps;
    }
}

int main() {
    //file();
    fast();

    int n, m;
    cin >> n >> m;
    vector<int> v(n-1);
    for(auto& i : v) {
        cin >> i;
    }
    v.insert(v.begin(),0);

    int lo = 0;
    int hi = iinf;
    int best = 0;

    while(hi >= lo) {
        int mi = lo + (hi-lo) / 2;

        if(works(v, mi, m)) {
            best = max(best, mi);
            lo = mi + 1;
        }
        else {
            hi = mi - 1;
        }
    }

    cout << best << endl;

    return 0;
}
