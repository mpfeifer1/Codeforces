#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n;
    cin >> n;

    deque<pair<int, int>> d(n);
    for(int i = 0; i < n; i++) {
        cin >> d[i].first;
        d[i].second = i;

    }

    sort(d.begin(), d.end());

    deque<int> ans(n);
    for(int i = 0; i < n; i++) {
        ans[d[(i+1)%n].second] = d[i].first;
    }

    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
}
