#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<ll, vector<ll>, greater<ll>> a;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push(temp);
    }

    ll total = 0;
    if(a.size() % 2 == 0) {
        a.push(0);
    }
    while(a.size() > 1) {
        ll here = 0;
        for(int i = 0; i < 3; i++) {
            here += a.top();
            a.pop();
        }
        total += here;
        a.push(here);
    }

    cout << total << endl;
}
