#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<int> alive;
    vector<int> killedby(n+1, 0);
    for(int i = 1; i <= n; i++) {
        alive.insert(i);
    }

    for(int i = 0; i < m; i++) {
        int lo, hi, win;
        cin >> lo >> hi >> win;

        vector<int> thisfight;

        for(auto it = alive.lower_bound(lo); it != alive.upper_bound(hi); it++) {
            if(*it < lo || *it > hi) {
                continue;
            }
            thisfight.push_back(*it);
        }

        for(auto i : thisfight) {
            if(i != win) {
                alive.erase(i);
                killedby[i] = win;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << killedby[i] << " ";
    }
    cout << endl;
}
