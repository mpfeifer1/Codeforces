#include <unordered_map>
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
    int n, m, k;
    cin >> n >> m >> k;

    // Read in colors of socks
    vector<int> socks(n);
    for(auto& i : socks) {
        cin >> i;
    }

    // Read in pairs of socks
    vector<int> d(n, -1);
    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--;
        n2--;

        join(d, n1, n2);
    }

    // Maps sock group to list of each sock's color
    unordered_map<int, vector<int>> v;
    for(int i = 0; i < d.size(); i++) {
        v[find(d, i)].push_back(socks[i]);
    }

    // For each sock group, count each frequency, add to total
    int total = 0;
    for(auto i : v) {
        if(i.second.size() > 1) {
            unordered_map<int, int> count;
            for(auto j : i.second) {
                count[j]++;
            }

            int best = 0;
            for(auto j : count) {
                best = max(best, j.second);
            }

            total += i.second.size() - best;
        }
    }

    cout << total << endl;
}
