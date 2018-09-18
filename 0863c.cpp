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





struct state {
    ll a, b;

    bool operator<(const state& s) const {
        if(a == s.a) {
            return b < s.b;
        }
        return a < s.a;
    }
};

ll winner(state s) {
    if((s.a + 1) % 3 + 1 == s.b) {
        return -1;
    }
    if((s.b + 1) % 3 + 1 == s.a) {
        return 1;
    }
    return 0;
}

int main() {
    //file();
    fast();

    // Read in input
    ll k;
    ll a, b;
    cin >> k >> a >> b;

    // Read in alice
    map<state, ll> anext;
    rep1(i, 3) {
        rep1(j, 3) {
            cin >> anext[{i,j}];
        }
    }

    // Read in bob
    map<state, ll> bnext;
    rep1(i, 3) {
        rep1(j, 3) {
            cin >> bnext[{i,j}];
        }
    }

    ll awins = 0;
    ll bwins = 0;

    map<state,ll> seen;
    vector<state> states;
    bool found = false;

    state curr = {a,b};
    while(k--) {
        ll win = winner(curr);
        if(win == -1) {
            awins++;
        }
        if(win == 1) {
            bwins++;
        }

        state next = {anext[curr], bnext[curr]};
        if(!found && seen.count(next)) {
            found = true;
            ll cyclestart = seen[next];
            ll cyclelength = states.size() - cyclestart;

            ll cyclea = 0;
            ll cycleb = 0;

            for(ll i = cyclestart; i < cyclelength + cyclestart; i++) {
                ll win = winner(states[i]);
                if(win == -1) {
                    cyclea++;
                }
                if(win == 1) {
                    cycleb++;
                }
            }

            ll totalcycles = k / cyclelength;
            k %= cyclelength;
            awins += totalcycles * cyclea;
            bwins += totalcycles * cycleb;

            //cout << "cycle length " << cyclelength << endl;
            //cout << "cycle a " << cyclea << endl;
            //cout << "cycle b " << cycleb << endl;
        }

        seen[next] = states.size();
        states.pb(next);

        curr = next;
    }

    cout << awins << " " << bwins << endl;

    return 0;
}
