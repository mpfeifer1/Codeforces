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




bool confirm(vector<int> count, string& s) {
    for(auto i : s) {
        count[i-'a']--;
    }

    for(auto i : count) {
        if(i != 0) {
            return false;
        }
    }
    return true;
}

bool oneedit(string& s1, string& s2) {
    int diff = 0;
    for(int i = 0; i < s1.size(); i++) {
        if(s1[i] != s2[i]) {
            diff++;
        }
    }

    bool same = false;
    unordered_set<char> u;
    for(auto i : s1) {
        if(u.count(i) > 0) {
            same = true;
            break;
        }
        u.insert(i);
    }

    return (diff == 0 && same) || (diff == 2);
}

int main() {
    //file();
    //fast();

    int k, n;
    cin >> k >> n;

    vector<string> v(k);
    for(auto& i : v) {
        cin >> i;
    }

    vector<int> count(26, 0);
    for(auto i : v[0]) {
        count[i-'a']++;
    }

    // If strings have different letter counts, quit
    for(auto i : v) {
        if(!confirm(count, i)) {
            cout << -1 << endl;
            return 0;
        }
    }

    unordered_set<string> s;
    for(auto i : v) {
        s.insert(i);
    }

    // Build checkpos, array of positions that are different. If too big, quit
    vector<int> checkpos;
    for(int i = 0; i < n; i++) {
        char first = v[0][i];
        for(int j = 1; j < k; j++) {
            if(v[j][i] != first) {
                checkpos.push_back(i);
                break;
            }
        }
    }

    // Grab first two same chars
    int totalsame = 0;
    for(int i = 0; i < n; i++) {
        char first = v[0][i];
        bool good = true;
        for(int j = 1; j < k; j++) {
            if(v[j][i] != first) {
                good = false;
                break;
            }
        }
        if(good) {
            checkpos.push_back(i);
            totalsame++;
            if(totalsame >= 2) {
                break;
            }
        }
    }

    // If too many to check, quit
    if(checkpos.size() > 50) {
        cout << -1 << endl;
        return 0;
    }

    // For each possiblilty, check
    string temp = v[0];
    for(int i = 0; i < checkpos.size(); i++) {
        for(int j = i+1; j < checkpos.size(); j++) {
            swap(temp[checkpos[i]], temp[checkpos[j]]);

            // check if all candidates work
            bool works = true;
            for(auto k : s) {
                if(!oneedit(k, temp)) {
                    works = false;
                    break;
                }
            }

            if(works) {
                cout << temp << endl;
                return 0;
            }

            swap(temp[checkpos[i]], temp[checkpos[j]]);
        }
    }

    cout << -1 << endl;
    return 0;
}
