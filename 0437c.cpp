#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int e;
    cin >> e;

    vector<int> costs(n);
    for(auto& i : costs) {
        cin >> i;
    }

    vector<vector<int>> adj(n);
    for(int i = 0; i < e; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--;
        n2--;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    vector<pair<int, int>> rem;
    for(int i = 0; i < costs.size(); i++) {
        rem.push_back({costs[i], i});
    }
    sort(rem.rbegin(), rem.rend());

    int total = 0;
    unordered_set<int> ignore;
    for(auto i : rem) {
        ignore.insert(i.second);
        for(auto j : adj[i.second]) {
            if(ignore.count(j) == 0) {
                total += costs[j];
            }
        }
    }

    cout << total << endl;
}
