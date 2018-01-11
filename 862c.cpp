#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n, x;
    cin >> n >> x;

    if(n == 1) {
        cout << "YES" << endl;
        cout << x << endl;
        return 0;
    }

    if(n == 2) {
        if(x == 0) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            cout << "0 " << x << endl;
        }
        return 0;
    }


    // Calculate answer
    ll total = 0;
    unordered_set<ll> ans;
    for(ll i = 1; i <= n-3; i++) {
        ans.insert(i);
        total ^= i;
    }

    // Calculate last 3 numbers
    int pw = 131072;
    if(x == total) {
        ans.insert(pw);
        ans.insert(pw<<1);
        ans.insert(pw + (pw<<1));
    }
    else {
        ans.insert(0);
        ans.insert(pw);
        ans.insert(pw ^ total ^ x);
    }

    // Print answer if no overlap
    cout << "YES" << endl;
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
}
