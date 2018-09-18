#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    unordered_set<int> seen;

    vector<int> ans(n,0);
    for(int i = n-1; i >= 0; i--) {
        seen.insert(v[i]);
        ans[i] = seen.size();
    }

    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;

        cout << ans[t-1] << endl;
    }
}
