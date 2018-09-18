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
const ld  prec = .0000001;

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





bool eq(ld d1, ld d2) {
    return abs(d1-d2) < prec;
}

ld dist(ld x1, ld y1, ld x2, ld y2) {
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

int main() {
    //file();
    //fast();

    ld r, x1, y1, x2, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;

    cout << fixed;
    cout.precision(10);

    // If Fafa not in flat
    if(dist(x1,y1,x2,y2) >= r) {
        cout << x1 << " " << y1 << " " << r << endl;
        return 0;
    }

    // If Fafa in center of flat
    if(eq(x1,x2) && eq(y1,y2)) {
        cout << x1+(r/2) << " " << y1 << " " << (r/2) << endl;
        return 0;
    }

    // If Fafa in flat, calculate midpoint
    ld rad = (r + dist(x1,y1,x2,y2))/2;

    // Find correct quadrant, add this in
    ld xdiff = x1-x2;
    ld ydiff = y1-y2;

    ld scale = rad / dist(x1,y1,x2,y2);

    ld x = x2+xdiff*scale;
    ld y = y2+ydiff*scale;

    cout << x << " " << y << " " << rad << endl;

    return 0;
}
