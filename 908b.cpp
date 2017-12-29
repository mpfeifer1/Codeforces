#include <bits/stdc++.h>

using namespace std;

int x, y;
int sx, sy;
int ex, ey;

bool solve(vector<char>& mapping, vector<vector<char>>& m, string s) {
    int currx = sx;
    int curry = sy;

    bool works = false;

    for(auto i : s) {
        char cmd;
        if(i == '0') {
            cmd = mapping[0];
        }
        if(i == '1') {
            cmd = mapping[1];
        }
        if(i == '2') {
            cmd = mapping[2];
        }
        if(i == '3') {
            cmd = mapping[3];
        }

        if(cmd == 'a') {
            currx++;
        }
        if(cmd == 'b') {
            currx--;
        }
        if(cmd == 'c') {
            curry++;
        }
        if(cmd == 'd') {
            curry--;
        }

        if(currx < 0 || curry < 0 || currx == x || curry == y) {
            works = false;
            break;
        }
        if(m[currx][curry] == '#') {
            works = false;
            break;
        }
        if(currx == ex && curry == ey) {
            works = true;
            break;
        }
    }

    return works;
}

int main() {
    cin >> x >> y;

    vector<vector<char>> m;
    m.resize(x, vector<char>(y));
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            cin >> m[i][j];
            if(m[i][j] == 'E') {
                ex = i;
                ey = j;
                m[i][j] = '.';
            }
            if(m[i][j] == 'S') {
                sx = i;
                sy = j;
                m[i][j] = '.';
            }
        }
    }

    string s;
    cin >> s;

    vector<char> mapping = {'a', 'b', 'c', 'd'};
    int total = 0;
    do {
        if(solve(mapping, m, s)) {
            total++;
        }
    } while(next_permutation(mapping.begin(), mapping.end()));

    cout << total << endl;
}
