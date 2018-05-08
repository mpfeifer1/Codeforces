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





void dump(vector<vector<char>> v) {
    cout << "YES" << endl;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < v[i].size(); j++) {
            cout << v[i][j];
        }
        cout << endl;
    }
}

int main() {
    //file();
    //fast();

    int n, k;
    cin >> n >> k;

    vector<vector<char>> v;
    v.resize(4, vector<char>(n,'.'));

    if(k % 2 == 0) {
        for(int i = 1; i <= k/2; i++) {
            v[1][i] = '#';
            v[2][i] = '#';
        }
        dump(v);
        return 0;
    }

    if(k <= (n-2)) {
        int mid = (n-1) / 2;

        for(int i = 0; i <= k/2; i++) {
            v[1][mid-i] = '#';
            v[1][mid+i] = '#';
        }
        dump(v);
        return 0;
    }

    if(k >= (n-2)+2) {
        for(int i = 1; i < n-1; i++) {
            v[1][i] = '#';
        }

        v[2][1] = '#';
        v[2][n-2] = '#';

        for(int i = 0; i < k-(n-2)-2; i++) {
            v[2][i+2] = '#';
        }


        dump(v);
        return 0;
    }

    cout << "NO" << endl;

    return 0;
}
