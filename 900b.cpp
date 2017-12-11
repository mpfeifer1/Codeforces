#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;

    a %= b;
    for(int i = 1; i < 10000; i++) {
        a *= 10;
        if(a/b == c) {
            cout << i << endl;
            return 0;
        }
        a %= b;
    }

    cout << -1 << endl;
}
