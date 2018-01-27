// Michael Pfeifer
// Version 02, 2018/01/17

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

ll readint(){
    char r;
    bool start=false,neg=false;
    ll ret=0;
    while(true){
        r=getchar();
        if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
            continue;
        }
        if((r-'0'<0 || r-'0'>9) && r!='-' && start){
            break;
        }
        if(start)ret*=10;
        start=true;
        if(r=='-')neg=true;
        else ret+=r-'0';
    }
    if(!neg) return ret;
    else return -ret;
}





int main() {
    //file();
    fast();

    int n, m;
    cin >> n >> m;

    if(n == 1 && m == 1) {
        cout << "YES" << endl;
        cout << 1 << endl;
        return 0;
    }

    if(n == 1 && m < 4) {
        cout << "NO" << endl;
        return 0;
    }

    if(m == 1 && n < 4) {
        cout << "NO" << endl;
        return 0;
    }

    if(n == 1) {
        cout << "YES" << endl;
        for(int i = 1; i <= m; i++) {
            if(i % 2 == 0) {
                cout << i << " ";
            }
        }
        for(int i = 1; i <= m; i++) {
            if(i % 2 == 1) {
                cout << i << " ";
            }
        }
        cout << endl;
        return 0;
    }

    if(m == 1) {
        cout << "YES" << endl;
        for(int i = 1; i <= n; i++) {
            if(i % 2 == 0) {
                cout << i << endl;
            }
        }
        for(int i = 1; i <= n; i++) {
            if(i % 2 == 1) {
                cout << i << endl;
            }
        }
        return 0;
    }

    if(n == 2 && m == 2) {
        cout << "NO" << endl;
        return 0;
    }

    if(n == 2 && m == 3) {
        cout << "NO" << endl;
        return 0;
    }

    if(n == 3 && m == 2) {
        cout << "NO" << endl;
        return 0;
    }

    if(n == 3 && m == 3) {
        cout << "YES" << endl;
        cout << "1 7 5" << endl;
        cout << "6 2 9" << endl;
        cout << "8 4 3" << endl;
        return 0;
    }

    // Build output
    vector<vector<int>> v(n, vector<int>(m, 0));
    int cnt = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            v[i][j] = cnt++;
        }
    }

    // Shift right two, down one
    if(n < m) {
        // Shift even rows two to the right
        for(int i = 0; i < n; i += 2) {
            int t1 = v[i][0], t2 = v[i][1];
            for(int j = 0; j < m-2; j++) {
                v[i][j] = v[i][j+2];
            }
            v[i][m-2] = t1;
            v[i][m-1] = t2;
        }

        // Shift even columns one down
        for(int i = 0; i < m; i += 2) {
            int t1 = v[0][i];
            for(int j = 0; j < n-1; j++) {
                v[j][i] = v[j+1][i];
            }
            v[n-1][i] = t1;
        }
    }

    // Shift down two, right one
    else {
        // Shift even rows one to the right
        for(int i = 0; i < n; i += 2) {
            int t1 = v[i][0];
            for(int j = 0; j < m-1; j++) {
                v[i][j] = v[i][j+1];
            }
            v[i][m-1] = t1;
        }

        // Shift even columns down two
        for(int i = 0; i < m; i += 2) {
            int t1 = v[0][i], t2 = v[1][i];
            for(int j = 0; j < n-2; j++) {
                v[j][i] = v[j+2][i];
            }
            v[n-2][i] = t1;
            v[n-1][i] = t2;
        }
    }

    // Print answer
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
