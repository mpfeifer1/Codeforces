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





void print(vector<vector<char>>& v) {
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            if(j==2 || j == 4) {
                cout << "-";
            }
            cout << v[i][j];
        }
        cout << endl;
    }
}
int main() {
    //file();
    //fast();

    vector<vector<char>> v;
    v.resize(6, vector<char>(6));

    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            char trash;
            if(j==2 || j == 4) {
                cin >> trash;
            }
            cin >> v[i][j];
        }
    }

    vector<pair<int,int>> pri;
    pri.pb({0,2});
    pri.pb({0,3});
    pri.pb({1,2});
    pri.pb({1,3});

    pri.pb({0,0});
    pri.pb({0,1});
    pri.pb({1,0});
    pri.pb({1,1});

    pri.pb({0,4});
    pri.pb({0,5});
    pri.pb({1,4});
    pri.pb({1,5});

    pri.pb({2,2});
    pri.pb({2,3});
    pri.pb({3,2});
    pri.pb({3,3});

    pri.pb({2,0});
    pri.pb({2,1});
    pri.pb({3,0});
    pri.pb({3,1});

    pri.pb({2,4});
    pri.pb({2,5});
    pri.pb({3,4});
    pri.pb({3,5});

    pri.pb({4,2});
    pri.pb({4,3});
    pri.pb({5,2});
    pri.pb({5,3});

    pri.pb({4,0});
    pri.pb({4,1});
    pri.pb({5,0});
    pri.pb({5,1});

    pri.pb({4,4});
    pri.pb({4,5});
    pri.pb({5,4});
    pri.pb({5,5});

    for(auto i : pri) {
        if(v[i.first][i.second] == '.') {
            v[i.first][i.second] = 'P';
            print(v);
            return 0;
        }
    }

    return 0;
}
