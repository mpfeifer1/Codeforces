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
const ll  inf  = 1e18 + iinf + 10;
const int mod  = 1000000007;
const ld  prec = .000001;

#define enld endl
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





bool cmp(pair<int,int>& p1, pair<int,int>& p2) {
    if(p1.first == p2.first) {
        if(p1.second == p2.second) {
            return false;
        }
        return p1.second > p2.second;
    }
    return p1.first < p2.first;
}


int search(vector<pair<int,int>>& arr, int maxcost, int maxidx) {
    // maxidx is highest we can't use
    // maxcost is the money we have available to use

    int lo = 0;
    int hi = maxidx - 1;
    int ans = 0;

    while(hi - lo >= 0) {
        int mi = lo + (hi - lo) / 2;
        if(arr[mi].first > maxcost) {
            hi = mi - 1;
        }
        else {
            ans = mi;
            lo = mi + 1;
        }
    }

    return arr[ans].second;
}

int main() {
    //file();
    //fast();

    int n, c, d;
    cin >> n >> c >> d;

    vector<pair<int,int>> coin, diam;
    for(int i = 0; i < n; i++) {
        int n1, n2;
        char c;
        cin >> n1 >> n2 >> c;
        if(c == 'C') {
            coin.pb({n2,n1});
        }
        else {
            diam.pb({n2,n1});
        }
    }

    // Sort on cost then beauty
    sort(all(coin), cmp);
    sort(all(diam), cmp);

    // Build prefix arrays
    vector<pair<int,int>> pre_coin;
    vector<pair<int,int>> pre_diam;

    pre_coin.pb({0,0});
    pre_diam.pb({0,0});

    for(int i = 0; i < coin.size(); i++) {
        pair<int,int> next = {coin[i].first, max(pre_coin.back().second, coin[i].second)};
        pre_coin.pb(next);
    }
    for(int i = 0; i < diam.size(); i++) {
        pair<int,int> next = {diam[i].first, max(pre_diam.back().second, diam[i].second)};
        pre_diam.pb(next);
    }

    pre_coin.pb({iinf,iinf});
    pre_diam.pb({iinf,iinf});

    // Set best
    int best = 0;

    // Get best if one coin, one diamond
    if(coin.size() > 0 && diam.size() > 0) {
        int s1 = search(pre_coin,c,pre_coin.size());
        int s2 = search(pre_diam,d,pre_diam.size());
        if(s1 > 0 && s2 > 0) {
            best = max(best, s1 + s2);
        }

    }

    // Get best if two coin
    if(coin.size() > 1) {
        for(int i = 1; i < coin.size(); i++) {
            int s = search(pre_coin, c-coin[i].first, i+1);
            if(s > 0) {
                best = max(best, s+coin[i].second);
            }
        }
    }

    // Get best if two diamond
    if(diam.size() > 1) {
        for(int i = 1; i < diam.size(); i++) {
            int s = search(pre_diam, d-diam[i].first, i+1);
            if(s > 0) {
                best = max(best, s+diam[i].second);
            }
        }
    }

    // Print answer
    cout << best << endl;

    return 0;
}
