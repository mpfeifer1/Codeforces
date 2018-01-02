#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    ll total = 0;
    for(int i = 0; i < m; i++) {
        total += v[i];
    }

    ll idx = 1;
    ll best = total;
    for(int i = m; i < n; i++) {
        total -= v[i-m];
        total += v[i];
        if(total < best) {
            best = total;
            idx = i - m + 2;
        }
    }

    cout << idx << endl;
}
