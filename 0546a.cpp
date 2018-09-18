#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll k, n, w;
    cin >> k >> n >> w;
    ll cost = (w * (w+1)) / 2;

    cost *= k;
    cost -= n;

    cout << max((ll)0, cost) << endl;
}
