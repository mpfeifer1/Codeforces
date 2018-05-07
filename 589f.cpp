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





struct dish {
    int start, end;
};

int choose(int c1, int c2, dish d1, dish d2, int e1, int e2, int t) {
    if(e1 >= t) {
        return c2;
    }
    if(e2 >= t) {
        return c1;
    }

    if(d1.end < d2.end) {
        return c1;
    }
    if(d2.end < d1.end) {
        return c2;
    }

    if(e1 < e2) {
        return c1;
    }
    else {
        return c2;
    }
}

bool works(vector<dish> v, int t) {
    int n = v.size();

    vector<int> eaten(n, 0);

    for(int i = 0; i <= 10000; i++) {
        int chosen = -1;
        for(int j = 0; j < n; j++) {
            if(i >= v[j].start && i < v[j].end) {
                if(chosen == -1) {
                    chosen = j;
                }
                else {
                    chosen = choose(chosen, j, v[chosen], v[j], eaten[chosen], eaten[j], t);
                }
            }
        }
        if(chosen >= 0) {
            eaten[chosen]++;
        }
    }

    bool good = true;
    for(int i = 0; i < n; i++) {
        if(eaten[i] < t) {
            good = false;
        }
    }

    return good;
}

int main() {
    //file();
    //fast();

    int n;
    cin >> n;

    vector<dish> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].start >> v[i].end;
    }

    int lo = 0;
    int hi = 10000;
    while(hi-lo>1) {
        int mi = (hi+lo)>>1;

        if(works(v,mi)) {
            lo = mi;
        }
        else {
            hi = mi;
        }
    }

    cout << lo * n << endl;

    return 0;
}
