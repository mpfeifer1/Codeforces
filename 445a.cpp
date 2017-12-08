#include <bits/stdc++.h>

using namespace std;

int n, m;

bool works(int i, int j) {
    if(i >= 0 && i < n && j >= 0 && j < m) {
        return true;
    }
    return false;
}

void dfs(vector<vector<char>>& v, int i, int j) {
    char here = v[i][j];
    char opp;

    if(here == 'B') {
        opp = 'W';
    }
    else {
        opp = 'B';
    }

    if(works(i-1, j) && v[i-1][j] == '.') {
        v[i-1][j] = opp;
        dfs(v, i-1, j);
    }
    if(works(i+1, j) && v[i+1][j] == '.') {
        v[i+1][j] = opp;
        dfs(v, i+1, j);
    }
    if(works(i, j-1) && v[i][j-1] == '.') {
        v[i][j-1] = opp;
        dfs(v, i, j-1);
    }
    if(works(i, j+1) && v[i][j+1] == '.') {
        v[i][j+1] = opp;
        dfs(v, i, j+1);
    }
}

int main() {
    cin >> n >> m;

    vector<vector<char>> v;
    v.resize(n, vector<char>(m));
    for(auto& i : v) {
        for(auto& j : i) {
            cin >> j;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == '.') {
                v[i][j] = 'B';
                dfs(v, i, j);
            }
        }
    }

    for(auto& i : v) {
        for(auto& j : i) {
            cout << j;
        }
        cout << endl;
    }
}
