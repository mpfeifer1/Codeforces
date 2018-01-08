#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);

    for(int i = 2; i <= n; i++) {
        int t;
        cin >> t;

        adj[t].push_back(i);
    }

    bool works = true;
    for(int i = 1; i <= n; i++) {
        int total = adj[i].size();
        if(total == 0) {
            continue;
        }

        int skip = 0;
        for(auto j : adj[i]) {
            if(adj[j].size() > 0) {
                skip++;
            }
        }

        total -= skip;

        if(total < 3) {
            works = false;
            break;
        }
    }

    if(works) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
