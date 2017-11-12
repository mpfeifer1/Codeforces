#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int last = v[v.size()-1];
    unordered_set<int> seen;
    for(int i = v.size()-1; i >= 0; i--) {
        if(seen.count(v[i]) == 0) {
            last = v[i];
            seen.insert(v[i]);
        }
    }

    cout << last << endl;
}
