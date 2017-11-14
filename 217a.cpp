#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>& d, int a) {
    if(d[a] == -1) {
        return a;
    }

    d[a] = find(d, d[a]);
    return d[a];
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);

    if(a == b) {
        return;
    }

    d[a] = b;
}


int main() {
    int n;
    cin >> n;

    vector<int> d(n+1, -1);

    vector<pair<int, int>> p;
    for(int i = 0; i < n; i++) {
        pair<int, int> pile;
        cin >> pile.first >> pile.second;
        p.push_back(pile);
    }

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(p[i].first == p[j].first || p[i].second == p[j].second) {
                join(d, i+1, j+1);
            }
        }
    }

    unordered_set<int> seen;
    for(int i = 1; i <= n; i++) {
        seen.insert(find(d, i));
    }

    cout << seen.size() - 1 << endl;
}
