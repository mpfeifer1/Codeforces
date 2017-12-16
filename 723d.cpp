#include <bits/stdc++.h>

using namespace std;

int n, m, l;

bool inrange(int x, int y) {
    if(x < 0 || y < 0 || x > n+1 || y > m+1) {
        return false;
    }
    return true;
}

void fill(vector<vector<char>>& v, int x, int y) {
    v[x][y] = '*';

    if(inrange(x-1, y) && v[x-1][y] == '.') {
        fill(v, x-1, y);
    }
    if(inrange(x+1, y) && v[x+1][y] == '.') {
        fill(v, x+1, y);
    }
    if(inrange(x, y-1) && v[x][y-1] == '.') {
        fill(v, x, y-1);
    }
    if(inrange(x, y+1) && v[x][y+1] == '.') {
        fill(v, x, y+1);
    }
}

int getsize(vector<vector<char>>& v, vector<vector<bool>>& vis, int x, int y) {
    vis[x][y] = true;

    int total = 1;

    if(inrange(x-1, y) && !vis[x-1][y] && v[x-1][y] == '.') {
        total += getsize(v, vis, x-1, y);
    }
    if(inrange(x+1, y) && !vis[x+1][y] && v[x+1][y] == '.') {
        total += getsize(v, vis, x+1, y);
    }
    if(inrange(x, y-1) && !vis[x][y-1] && v[x][y-1] == '.') {
        total += getsize(v, vis, x, y-1);
    }
    if(inrange(x, y+1) && !vis[x][y+1] && v[x][y+1] == '.') {
        total += getsize(v, vis, x, y+1);
    }

    return total;
}

int main() {
    cin >> n >> m >> l;

    vector<vector<char>> v;
    v.resize(n+2, vector<char>(m+2, '.'));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }

    vector<vector<bool>> vis;
    vis.resize(n+2, vector<bool>(m+2, false));

    getsize(v, vis, 0, 0);

    // List of Size, (X,Y)
    vector<pair<int, pair<int,int>>> lakes;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(v[i][j] == '.' && !vis[i][j]) {
                int size = getsize(v, vis, i, j);
                lakes.push_back({size, {i,j}});
            }
        }
    }

    sort(lakes.rbegin(), lakes.rend());

    int cost = 0;
    while(lakes.size() > l) {
        cost += lakes.back().first;
        pair<int,int> coords = lakes.back().second;
        lakes.pop_back();
        fill(v, coords.first, coords.second);
    }

    cout << cost << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << v[i][j];
        }
        cout << endl;
    }
}
