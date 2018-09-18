#include <bits/stdc++.h>

using namespace std;

bool solve(string& s1, string& s2, int i, int j) {
    vector<vector<bool>> v;
    v.resize(s1.size(), vector<bool>(s2.size(), false));

    queue<pair<int, int>> q;
    q.push({i,j});
    v[i][j] = true;
    int count = 1;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(s2[y] == '^') {
            if(x > 0 && !v[x-1][y]) {
                count++;
                q.push({x-1,y});
                v[x-1][y] = true;
            }
        }

        else {
            if(x < s1.length()-1 && !v[x+1][y]) {
                count++;
                q.push({x+1,y});
                v[x+1][y] = true;
            }
        }

        if(s1[x] == '<') {
            if(y > 0 && !v[x][y-1]) {
                count++;
                q.push({x,y-1});
                v[x][y-1] = true;
            }
        }

        else {
            if(y < s2.length()-1 && !v[x][y+1]) {
                count++;
                q.push({x,y+1});
                v[x][y+1] = true;
            }
        }

    }

    return count == s1.size() * s2.size();
}

int main() {
    int n, m;
    cin >> n >> m;

    string s1, s2;
    cin >> s1 >> s2;

    bool works = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            works &= solve(s1, s2, i, j);
        }
    }

    if(works) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
