#include <bits/stdc++.h>

using namespace std;

int inf = 500;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    vector<vector<int>> dp;
    dp.resize(n + 1, vector<int>(3,inf));

    dp[0][0] = 0;

    for(int i = 1; i <= n; i++) {
        dp[i][0] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) + 1;
        if(v[i-1] & 1) {
            dp[i][1] = min({dp[i-1][0], dp[i-1][2]});
        }
        if(v[i-1] & 2) {
            dp[i][2] = min({dp[i-1][0], dp[i-1][1]});
        }
    }

    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << endl;
}
