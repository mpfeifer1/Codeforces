#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> lst;
    vector<vector<bool>> mtr;

    lst.resize(n);
    mtr.resize(n, vector<bool>(n, false));

    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        n1--;
        n2--;

        lst[n1].push_back(n2);
        mtr[n1][n2] = true;
    }

    int all = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                continue;
            }

            int total = 0;
            for(auto k : lst[i]) {
                if(mtr[k][j]) {
                    total++;
                }
            }

            all += total * (total - 1) / 2;
        }
    }

    cout << all << endl;
}
