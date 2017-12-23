#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> q;

    ll total = 0;
    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;

        if(q.size() > 0 && q.top() < m) {
            total += m - q.top();
            q.push(m);
            q.pop();
        }
        q.push(m);
    }

    cout << total << endl;
}
