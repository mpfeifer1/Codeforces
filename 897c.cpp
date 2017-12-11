#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll f[100];
ll mx;

string z = "What are you doing while sending \"";
string s = "What are you doing at the end of the world? Are you busy? Will you save us?";
string m = "\"? Are you busy? Will you send \"";

char dfs(ll pos, int n) {
    if(n == 1) {
        return s[pos];
    }
    if(pos < 34) {
        return z[pos];
    }
    if(pos >= f[n-1] + 34 && pos < f[n-1] + 66) {
        pos -= f[n-1] + 34;
        return m[pos];
    }
    if(pos == f[n] - 1) {
        return '?';
    }
    if(pos == f[n] - 2) {
        return '\"';
    }
    if(pos < f[n-1] + 34) {
        return dfs(pos-34, n-1);
    }

    return dfs(pos - f[n-1] - 66, n-1);
}

int main() {
    int q;
    cin >> q;

    f[1] = s.size();
    for(int i = 2; i < 100; i++) {
        f[i] = f[i-1] + f[i-1] + 68;
        if(f[i] > 1e18) {
            mx = i;
            break;
        }
    }

    vector<char> res;

    while(q--) {
        ll n, k;
        cin >> n >> k;

        k--;
        n++;

        if(n > mx) {
            ll dd = n - mx;
            if(k >= dd * 34) {
                k -= dd * 34;
                n = mx;
            }
            else {
                res.push_back(z[k % 34]);
                continue;
            }
        }
        if(k > f[n] - 1) {
            res.push_back('.');
            continue;
        }
        res.push_back(dfs(k, min(mx,n)));
    }

    for(char c : res) {
        cout << c;
    }
    cout << endl;
}
