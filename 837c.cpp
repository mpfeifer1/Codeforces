#include <bits/stdc++.h>

using namespace std;

int n, a, b;

int value(vector<pair<int,int>>& seals, int i) {
    return seals[i].first * seals[i].second;
}

bool solve(int c, int d, int e, int f) {
    int v1 = max(c, e);
    int v2 = d + f;
    if(v1 < v2) {
        swap(v1, v2);
    }

    return (v1 <= a) && (v2 <= b);
}

bool works(vector<pair<int,int>>& seals, int i, int j) {
    // For each combo of 4, solve
    int c, d, e, f;
    c = seals[i].first;
    d = seals[i].second;
    e = seals[j].first;
    f = seals[j].second;

    bool good = false;
    good |= solve(c, d, e, f);
    good |= solve(d, c, e, f);
    good |= solve(c, d, f, e);
    good |= solve(d, c, f, e);

    return good;
}

int main() {
    cin >> n >> a >> b;
    if(a < b) {
        swap(a,b);
    }

    vector<pair<int,int>> seals(n);
    for(auto& i : seals) {
        cin >> i.first >> i.second;
    }

    int best = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                continue;
            }

            if(works(seals, i, j)) {
                best = max(best, value(seals, i) +
                                 value(seals, j));
            }
        }
    }

    cout << best << endl;
}
