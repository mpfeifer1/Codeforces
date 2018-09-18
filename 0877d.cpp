#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 61;

const int maxn = 1007;
const int jump[4][2] = {0,1,0,-1,1,0,-1,0};

int n, m, k, ex, ey, x, y;
int step[maxn][maxn];
char mp[maxn][maxn];

int bfs() {
    memset(step, -1, sizeof(step));
    queue<pair<int,int>> q;
    step[x][y] = 0;
    q.push({x,y});

    while(!q.empty()) {
        tie(x,y) = q.front();
        q.pop();

        if(step[ex][ey] != -1) {
            return step[ex][ey];
        }

        for(int i = 0; i < 4; i++) {
            for(int len = 1; len <= k; len++) {
                int h = x + jump[i][0] * len;
                int l = y + jump[i][1] * len;
                if(h < 1 || h > n || l < 1 || l > m || mp[h][l] == '#') {
                    break;
                }
                if(step[h][l] == -1) {
                    step[h][l] = step[x][y] + 1;
                    q.push({h,l});
                }
            }
        }
    }

    return -1;
}

int main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        cin >> (mp[i]+1);
    }

    cin >> x >> y >> ex >> ey;
    cout << bfs() << endl;
}
