#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
ll inf = (ll)1 << 55;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<ll> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    // Edge case if there's already a 1
    int non = 0;
    bool one = false;
    for(int i = 0; i < n; i++) {
        if(v[i] == 1) {
            one = true;
        }
        else {
            non++;
        }
    }
    if(one) {
        cout << non << endl;
        return 0;
    }

    // Check that there's a solution
    ll test = v[0];
    for(int i = 1; i < n; i++) {
        test = __gcd(v[i], test);
    }
    if(test != 1) {
        cout << "-1" << endl;
        return 0;
    }

    // Solve
    for(ll i = 0; i < n; i++) {
        bool f = false;
        for(ll j = 0; j < n-i-1; j++) {
            v[j] = __gcd(v[j], v[j+1]);
            if(v[j] == 1) {
                f = true;
            }
        }

        if(f) {
            cout << n + i << endl;
            return 0;
        }
    }
}
