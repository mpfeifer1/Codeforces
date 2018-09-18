#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll getval(ll n) {
    string s = to_string(n);
    string s2 = s;
    reverse(s2.begin(), s2.end());

    s += s2;

    return stoll(s);
}

int main() {
    ll k, p;
    cin >> k >> p;

    ll total = 0;
    for(ll i = 1; i <= k; i++) {
        total += getval(i);
        total %= p;
    }

    cout << total % p << endl;
}
