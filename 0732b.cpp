#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v[i] = temp;
        ans[i] = temp;
    }

    int total = 0;
    for(int i = 1; i < n; i++) {
        if(k - ans[i-1] > ans[i]) {
            total += k - ans[i] - ans[i-1];
            ans[i] = k - ans[i-1];
        }
    }

    cout << total << endl;
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
}
