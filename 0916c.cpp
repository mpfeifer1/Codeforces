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
#define umap unordered_map;
#define uset unordered_set;

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





struct edge {
    int n1, n2, w;
};

bool isprime(int n) {
    if(n == 2) {
        return true;
    }
    if(n % 2 == 0) {
        return false;
    }

    for(int i = 3; i < sqrt(n) + 1; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    //file();
    //fast();

    int n, m;
    cin >> n >> m;

    vector<edge> v;

    int p = n;
    while(!isprime(p)) {
        p++;
    }

    set<pair<int,int>> seen;
    for(int i = 1; i < n-1; i++) {
        v.push_back({i, i+1, 1});
        seen.insert({i,i+1});
    }
    v.push_back({n-1, n, p-(n-2)});
    seen.insert({n-1,n});


    int n1=0, n2=2;
    while(v.size() < m) {
        n1++;
        if(n1 == n2-1) {
            n1 = 1;
            n2++;
        }

        pair<int,int> val = {min(n1,n2), max(n1,n2)};

        if(seen.count(val)>0) {
            continue;
        }

        v.push_back({n1, n2, p+1});
        seen.insert(val);
    }

    // Print answer
    cout << p << " " << p << endl;
    for(auto i : v) {
        cout << i.n1 << " " << i.n2 << " " << i.w << endl;
    }

}
