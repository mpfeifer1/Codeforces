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
    //fast();

    string s;
    cin >> s;
    int n = s.size();

    vector<vector<bool>> works;
    works.resize(n, vector<bool>(n, true));

    // Remove if too many close
    for(int i = 0; i < n; i++) {
        int open = 0;
        int close = 0;
        int question = 0;
        bool good = true;
        for(int j = i; j < n; j++) {
            if(s[j] == '(') {
                open++;
            }
            if(s[j] == ')') {
                close++;
            }
            if(s[j] == '?') {
                question++;
            }

            if(!good || close > question+open) {
                good = false;
                works[i][j] = false;
            }
        }
    }

    // Remove if too many open
    for(int i = n-1; i >= 0; i--) {
        int open = 0;
        int close = 0;
        int question = 0;
        bool good = true;
        for(int j = i; j >= 0; j--) {
            if(s[j] == '(') {
                open++;
            }
            if(s[j] == ')') {
                close++;
            }
            if(s[j] == '?') {
                question++;
            }

            if(!good || open > question+close) {
                good = false;
                works[j][i] = false;
            }
        }
    }

    // Count where size!=0 and size%2==0
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int size = j - i + 1;
            if(works[i][j] && size%2 == 0) {
                count++;
            }
        }
    }

    cout << count << endl;
}
