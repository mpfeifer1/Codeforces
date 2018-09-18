// Michael Pfeifer
// Version 03, 2018/01/30

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

    int n;
    cin >> n;

    int n1;
    cin >> n1;
    queue<int> q1;
    for(int i = 0; i < n1; i++) {
        int t; cin >> t;
        q1.push(t);
    }

    int n2;
    cin >> n2;
    queue<int> q2;
    for(int i = 0; i < n2; i++) {
        int t; cin >> t;
        q2.push(t);
    }

    set<pair<queue<int>,queue<int>>> s;


    int times = 0;
    while(true) {
        if(s.count({q1,q2})) {
            cout << "-1" << endl;
            return 0;
        }

        if(q1.empty() || q2.empty()) {
            break;
        }

        times++;
        s.insert({q1,q2});

        int v1 = q1.front();
        int v2 = q2.front();
        q1.pop();
        q2.pop();
        if(v1 > v2) {
            q1.push(v2);
            q1.push(v1);
        }
        else {
            q2.push(v1);
            q2.push(v2);
        }

    }

    if(q1.empty()) {
        cout << times << " 2" << endl;
    }
    else {
        cout << times << " 1" << endl;
    }

    return 0;
}
