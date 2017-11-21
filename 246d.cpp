#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, unordered_set<int>> s;

    vector<int> v(n);
    for(auto& i : v) {
        cin >> i;
        s[i] = {};
    }

    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1 = v[n1-1];
        n2 = v[n2-1];

        if(n1 != n2) {
            s[n1].insert(n2);
            s[n2].insert(n1);
        }
    }

    int bestval = 0, bestidx = 1000000;
    for(auto i : s) {
        if(i.second.size() > bestval) {
            bestval = i.second.size();
            bestidx = i.first;
        }
        if(i.second.size() == bestval) {
            bestidx = min(i.first, bestidx);
        }
    }

    cout << bestidx << endl;
}
