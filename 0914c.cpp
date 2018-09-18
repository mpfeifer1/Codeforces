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





int countbits(int n) {
    int total = 0;
    while(n > 0) {
        if(n%2==1) {
            total++;
        }
        n /= 2;
    }
    return total;
}

ll ncr[1001][1001];
void setupchoose() {
    for(int i = 0; i <= 1000; i++) {
        ncr[i][0] = 1;
    }
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= 1000; j++) {
            ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j])%mod;
        }
    }
}
ll choose(ll n, ll k) {
    return ncr[n][k];
}

int main() {
    //file();
    //fast();

    setupchoose();

    vector<int> dp(1001);
    dp[1] = 0;
    for(int i = 2; i <= 1000; i++) {
        dp[i] = dp[countbits(i)] + 1;
    }

    string n;
    int k;
    cin >> n >> k;

    if(k == 0) {
        cout << 1 << endl;
        return 0;
    }

    ll ones = 0, ans = 0;
    for(int i = 0; i < n.size(); i++) {
        if(n[i] == '0') {
            continue;
        }

        for(int j = max(ones, 1ll); j < 1000; j++) {
            if(dp[j] == k-1) {
                ans += choose(n.size()-i-1, j-ones);
                ans %= mod;
                if(i == 0 && k == 1) {
                    ans--;
                    ans += mod;
                    ans %= mod;
                }
            }
        }

        ones++;
    }

    int count = 0;
    for(int i = 0; i < n.size(); i++) {
        if(n[i] == '1') {
            count++;
        }
    }
    if(dp[count] == k-1) {
        ans++;
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}
