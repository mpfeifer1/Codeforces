#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf = 1000;

int main() {
    int n, d;
    cin >> n >> d;

    string s;
    cin >> s;

    vector<int> v(n, inf);

    queue<int> q;
    q.push(0);
    v[0] = 0;

    for(int j = 0; j < n; j++) {
        for(int i = 1; i <= d && i+j < n; i++) {
            if(s[j+i] == '1') {
                v[j+i] = min(v[j] + 1, v[j+i]);
            }
        }
    }

    if(v[n-1] == inf) {
        cout << -1 << endl;
        return 0;
    }

    cout << v[n-1] << endl;
}
