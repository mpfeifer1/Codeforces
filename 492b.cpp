#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    ll n, l;
    cin >> n >> l;

    vector<ld> v(n);
    for(auto& i : v) {
        cin >> i;
    }
    sort(v.begin(), v.end());

    ld ans = max(v.front(), l-v.back());
    for(int i = 1; i < v.size(); i++) {
        ans = max(ans, (v[i]-v[i-1]) / 2.0l);
    }

    cout << fixed;
    cout.precision(10);
    cout << ans << endl;
}
