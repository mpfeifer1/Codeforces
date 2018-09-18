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





int MAXN = 5005;
vector<vector<int>> memo(MAXN, vector<int>(MAXN,-1));

int solve(int a, int b, vector<vector<int>>& arr) {
    if(a > b) return 0;

    if(memo[a][b] != -1) {
        return memo[a][b];
    }

    int ans = max({arr[a][b], solve(a+1,b,arr), solve(a, b-1,arr)});
    memo[a][b] = ans;
    return ans;
}

int main() {
    //file();
    fast();

    map<pair<int,int>, int> m;

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    vector<vector<int>> vals(n, vector<int>(n,0));
    vector<vector<int>> memo(n, vector<int>(n,0));

    for(int i = 0; i < n; i++) {
        for(int j = i; j >= 0; j--) {
            if(j == i) {
                vals[j][i] = v[i];
            }
            else {
                vals[j][i] = vals[j+1][i] ^ vals[j][i-1];
            }
        }
    }

    /*
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << vals[i][j] << " ";
        }
        cout << endl;
    }
    */

    int q;
    cin >> q;
    while(q--) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--; n2--;
        cout << solve(n1,n2,vals) << endl;
    }

    return 0;
}
