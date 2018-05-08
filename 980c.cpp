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





int find(vector<int>& d, int a) {
    if(d[a] <= -1) {
        return a;
    }
    return d[a] = find(d, d[a]);
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);

    if(a == b) return;

    if(a > b) {
        swap(a,b);
    }

    d[a] += d[b];
    d[b] = a;
}

int size(vector<int>& d, int a) {
    a = find(d, a);
    return -d[a];
}

int main() {
    //file();
    //fast();

    vector<int> d(256, -1);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    for(int i = 0; i < n; i++) {
        int curr = v[i];

        while(curr > 0 && (find(d, curr) == find(d,curr-1) || size(d,curr) + size(d,curr-1) <= k)) {
            join(d, curr, curr-1);
            curr--;
        }

        v[i] = find(d, v[i]);
    }

    for(auto i : v) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
