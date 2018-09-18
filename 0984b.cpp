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





int n, m;

bool inrange(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

bool isvalid(vector<vector<char>>& v, int i, int j) {
    if(v[i][j] == '*') return true;

    int bombs = 0;
    int count = v[i][j] - '0';
    if(v[i][j] == '.') count = 0;

    for(int k = -1; k <= 1; k++) {
        for(int l = -1; l <= 1; l++) {
            if(k == l && k == 0) continue;
            if(inrange(i+k, j+l)) {
                if(v[i+k][j+l] == '*') bombs++;
            }
        }
    }

    return bombs == count;
}

int main() {
    //file();
    //fast();

    cin >> n >> m;
    vector<vector<char>> v;
    v.resize(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    bool works = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!isvalid(v, i, j)) works = false;
        }
    }

    if(works) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
