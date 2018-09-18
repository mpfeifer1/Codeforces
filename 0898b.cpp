#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    for(int i = 0; i * a <= n; i++) {
        if((n - (i * a)) % b == 0) {
            cout << "YES" << endl;
            cout << i << " " << (n - (i*a)) / b << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}
