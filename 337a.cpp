#include <bits/stdc++.h>

using namespace std;

int inf = 1 << 30 - 1;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(m);
    for(auto& i : v) {
        cin >> i;
    }

    sort(v.begin(), v.end());

    n--;
    int ans = inf;
    for(int i = 0; i < v.size()-n; i++) {
        ans = min(ans, v[i+n] - v[i]);
    }

    cout << ans << endl;
}
