#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll conn(ll a) {
    return a * (a-1) / 2;
}

int main() {
    ll a, b;
    cin >> a >> b;

    ll max = conn(a-(b-1));

    ll size = a/b;
    ll leftover = a % b;
    ll min = b * conn(size);
    min -= leftover * conn(size);
    min += leftover * conn(size+1);


    cout << min << " " << max << endl;
}
