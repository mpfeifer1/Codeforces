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




int n;
string big;
string ans;
bool done = false;
vector<int> countarr(10, 0);
int sless = 0;

void search() {
    // Quit when done
    if(done) {
        return;
    }

    // If permutation full, print
    if(ans.size() >= n) {
        cout << ans << endl;
        done = true;
        return;
    }

    // For each letter
    for(int i = 9; i >= 0; i--) {
        // Quit when done
        if(done) {
            break;
        }

        // If we can take it
        if(countarr[i] > 0 && (sless > 0 || (i+'0') <= big[ans.size()])) {
            if((i+'0') < big[ans.size()]) {
                sless++;
            }
            countarr[i]--;
            ans.push_back(i+'0');
            search();
            ans.pop_back();
            countarr[i]++;
            if((i+'0') < big[ans.size()]) {
                sless--;
            }
        }
    }
}

int main() {
    //file();
    //fast();

    string s1, s2;
    cin >> s1 >> s2;

    if(s2.length() > s1.length()) {
        sort(rall(s1));
        cout << s1 << endl;
        return 0;
    }

    n = s1.length();
    big = s2;
    for(auto i : s1) {
        countarr[i-'0']++;
    }

    search();
}
