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





ll countbits(ll n) {
    ll sum = 0;
    while(n > 0) {
        if(n % 2 == 1) {
            sum++;
        }
        n >>= 1;
    }
    return sum;
}

int main() {
    //file();
    fast();

    ll n, k;
    cin >> n >> k;

    // Count if there are enough bits
    ll bits = countbits(n);
    if(bits > k) {
        cout << "No" << enld;
        return 0;
    }

    // Build binary representation
    vector<ll> represent;
    while(n > 0) {
        if(n % 2 == 1) {
            represent.push_back(1);
        }
        else {
            represent.push_back(0);
        }
        n >>= 1;
    }
    reverse(all(represent));

    // Build initial state
    ll idx = 0;
    ll initsize = represent.size()-1;
    ll bitsneeded = k - bits;

    // While we're able to break the biggest apart
    while(bitsneeded > 0) {
        // Find frist non-zero
        while(represent[idx] == 0) {
            idx++;
        }

        // If no 'last' element, add it
        if(idx == represent.size()-1) {
            represent.push_back(0);
        }

        // If we can break apart everything here, do it
        if(represent[idx] <= bitsneeded) {
            bitsneeded -= represent[idx];
            represent[idx+1] += represent[idx]*2;
            represent[idx] = 0;
        }

        // Otherwise, start breaking the smallest
        else {
            break;
        }
    }

    // Find last one
    idx = represent.size()-1;
    while(represent[idx] == 0) {
        idx--;
    }

    // While we're able to break apart the smallest
    while(bitsneeded > 0) {
        // If no 'last' element, add it
        if(idx == represent.size()-1) {
            represent.push_back(0);
        }

        if(represent[idx] > 0) {
            represent[idx]--;
            represent[idx+1] += 2;
            bitsneeded--;
        }

        idx++;
    }

    // Print answer
    cout << "Yes" << endl;
    for(ll i = 0; i < represent.size(); i++) {
        for(ll j = 0; j < represent[i]; j++) {
            cout << initsize << " ";
        }
        initsize--;
    }
    cout << endl;
}
