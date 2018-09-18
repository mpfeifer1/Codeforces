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





int find(vector<int>& d, int a) {
    if(d[a] < 0) return a;
    return d[a] = find(d, d[a]);
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);
    if(a == b) return;
    d[b] += d[a];
    d[a] = b;
}

int size(vector<int>& d, int a) {
    a = find(d, a);
    return -d[a];
}

int main() {
    //file();
    //fast();

    int n;
    cin >> n;

    map<int,int> conv;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        conv[v[i]] = i;
    }

    vector<int> d;
    d.resize(n, -1);

    map<int,int> sizes;

    int bestval = -1;
    int bestloc = -1;

    for(auto th : conv) {
        int i = th.first;
        int idx = th.second;
        sizes[1]++;

        // join left
        if(idx > 0) {
            if(v[idx] > v[idx-1]) {
                sizes[size(d,idx)]--;
                sizes[size(d,idx-1)]--;

                if(sizes[size(d,idx)] == 0) sizes.erase(size(d,idx));
                if(sizes[size(d,idx-1)] == 0) sizes.erase(size(d,idx-1));

                join(d, idx, idx-1);
                sizes[size(d, idx)]++;
            }
        }

        // join right
        if(idx < n-1) {
            if(v[idx] > v[idx+1]) {
                sizes[size(d,idx)]--;
                sizes[size(d,idx+1)]--;

                if(sizes[size(d,idx)] == 0) sizes.erase(size(d,idx));
                if(sizes[size(d,idx+1)] == 0) sizes.erase(size(d,idx+1));

                join(d, idx, idx+1);
                sizes[size(d, idx)]++;
            }
        }

        if(sizes.size() == 1) {
            int groups = (*sizes.begin()).second;
            if(groups > bestloc) {
                bestloc = groups;
                bestval = i;
            }
            if(groups == bestloc) {
                if(i < bestval) {
                    bestval = i;
                }
            }
        }
    }

    cout << bestval + 1 << endl;

    return 0;
}
