#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> adj;
    adj.resize(n, vector<bool>(n, false));
    vector<int> deg(n, 0);
    string ans(n, 'c');

    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        n1--;
        n2--;

        adj[n1][n2] = true;
        adj[n2][n1] = true;

        deg[n1]++;
        deg[n2]++;
    }

    for(int i = 0; i < n; i++) {
        if(deg[i] == n-1) {
            ans[i] = 'b';
        }
    }

    for(int i = 0; i < n; i++) {
        if(ans[i] == 'c') {
            ans[i] = 'a';
            for(int j = 0; j < n; j++) {
                if(adj[i][j] && ans[j] != 'b') {
                    ans[j] = 'a';
                }
            }
            break;
        }
    }

    bool works = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                continue;
            }
            if((ans[i] == 'a' && ans[j] == 'c') ||
               (ans[i] == 'c' && ans[j] == 'a')) {
                works &= !adj[i][j];
            }
            else {
                works &= adj[i][j];
            }
        }
    }

    if(works) {
        cout << "Yes" << endl << ans << endl;
    }
    else {
        cout << "No" << endl;
    }
}
