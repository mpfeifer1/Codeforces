#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> v(n);
    for(auto& i : v) {
        cin >> i.first >> i.second;
    }

    vector<vector<int>> dp;
    dp.resize(n+1, vector<int>(3, 0));

    for(int i = 0; i < n; i++) {
        ll l_tree;
        ll m_tree = v[i].second;
        ll l_dist = 0;
        ll r_dist = 0;

        // Get tree info
        if(i > 0) {
            l_tree = v[i-1].second;
        }
        if(i > 0) {
            l_dist = v[i].first - v[i-1].first;
        }
        if(i < n-1) {
            r_dist = v[i+1].first - v[i].first;
        }

        // If can fall left
        if(i == 0 || m_tree < l_dist) {
            dp[i+1][0] = max(dp[i][0], dp[i][1]) + 1;

            // If previous also fell right
            if(l_tree + m_tree < l_dist) {
                dp[i+1][0] = max(dp[i+1][0], dp[i][2] + 1);
            }
        }

        // No fall
        dp[i+1][1] = max({dp[i][0], dp[i][1], dp[i][2]});

        // If can fall right
        if(i == n-1 || m_tree < r_dist) {
            dp[i+1][2] = max({dp[i][0], dp[i][1], dp[i][2]}) + 1;
        }
    }

    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
}
