#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll a, b;
    cin >> a >> b;

    ll x, y, z;
    cin >> x >> y >> z;

    ll yneeded = 2 * x + y;
    ll bneeded = 3 * z + y;

    cout << max(yneeded-a,0ll) + max(bneeded - b,0ll) << endl;
}
