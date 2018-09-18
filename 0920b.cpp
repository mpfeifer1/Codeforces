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





struct student {
    int beg, end;
    int time, idx;
};

bool cmp(student s1, student s2) {
    return s1.beg < s2.beg;
}

bool cmp2(student s1, student s2) {
    return s1.idx < s2.idx;
}

int main() {
    //file();
    //fast();

    int cases;
    cin >> cases;

    while(cases--) {
        int n;
        cin >> n;

        vector<student> v(n);
        int idx = 0;
        for(auto& i : v) {
            cin >> i.beg >> i.end;
            i.time = 0;
            i.idx = idx;
            idx++;
        }

        stable_sort(all(v), cmp);

        int time = 1;

        for(int i = 0; i < v.size(); i++) {
            if(v[i].beg > time) {
                time++;
                i--;
                continue;
            }
            if(v[i].end >= time) {
                v[i].time = time;
                time++;
            }
        }

        sort(all(v), cmp2);

        for(auto i : v) {
            cout << i.time << " ";
        }
        cout << endl;
    }

    return 0;
}
