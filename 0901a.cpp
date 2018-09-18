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

#define enld endl
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

    int levels;
    cin >> levels;

    vector<int> v(levels+1);
    for(auto& i : v) {
        cin >> i;
    }

    bool ambig = false;
    for(int i = 1; i < v.size(); i++) {
        if(v[i-1] >= 2 && v[i] >= 2) {
            ambig = true;
            break;
        }
    }

    if(!ambig) {
        cout << "perfect" << endl;
        return 0;
    }

    vector<int> tree1, tree2;

    bool split = false;

    int par = 0;
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i]; j++) {
            tree1.pb(par);
            tree2.pb(par);
        }
        par += v[i];

        if(!split && i > 0 && (v[i-1] >= 2 && v[i] >= 2)) {
            int next = tree2.back()-1;
            tree2.pop_back();
            tree2.push_back(next);
            split = true;
        }
    }

    cout << "ambiguous" << enld;
    for(auto& i : tree1) {
        cout << i << " ";
    }
    cout << enld;
    for(auto& i : tree2) {
        cout << i << " ";
    }
    cout << enld;
}
