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





struct group {
char color;
int size;
};

int main() {
    //file();
    //fast();

    string s;
    cin >> s;

    vector<group> g;
    g.pb({s[0],1});
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == s[i-1]) {
            g.back().size++;
        }
        else {
            g.pb({s[i],1});
        }
    }

    int op = 0;
    while(g.size() > 1) {
        vector<group> next;
        for(int i = 0; i < g.size(); i++) {
            // If first or last
            if(i == 0 || i == g.size()-1) {
                next.pb({g[i].color, g[i].size-1});
            }

            // If middle
            else {
                next.pb({g[i].color, g[i].size-2});
            }

            // If group is empty, drop
            if(next.back().size <= 0) {
                next.pop_back();
                continue;
            }

            // If groups can be merged, merge
            if(next.size() >= 2) {
                if(next[next.size()-1].color == next[next.size()-2].color) {
                    int t = next.back().size;
                    next.pop_back();
                    next.back().size += t;
                }
            }
        }
        g.swap(next);
        op++;
    }

    cout << op << endl;
}
