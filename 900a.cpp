#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    ll less = 0;
    ll greater = 0;
    for(int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;

        if(a < 0) {
            less++;
        }
        if(a > 0) {
            greater++;
        }
    }

    if(less >= 2 && greater >= 2) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
}
