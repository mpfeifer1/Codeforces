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
const int iinf = 1e9 + 10;
const ll  inf  = 1e18 + 10;
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
    //fast();

    int n, pos, l, r;
    cin >> n >> pos >> l >> r;

    int l1 = l;
    int r1 = r;
    int pos1 = pos;
    int total1 = 0;
    if(l1 > 1) {
        total1 += abs(pos1 - l1);
        total1++;
        pos1 = l1;
    }

    if(r1 < n) {
        total1 += abs(pos1 - r1);
        total1++;
    }

    int l2 = l;
    int r2 = r;
    int pos2 = pos;
    int total2 = 0;

    if(r2 < n) {
        total2 += abs(pos2 - r2);
        total2++;
        pos2 = r2;
    }

    if(l2 > 1) {
        total2 += abs(pos2 - l2);
        total2++;
    }

    cout << min(total1, total2) << endl;

}
