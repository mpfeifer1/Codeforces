#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    vector<ll> odd;

    ll total = 0;
    for(ll i = 0; i < n; i++) {
        ll temp;
        cin >> temp;

        if(temp % 2 == 0) {
            if(temp > 0) {
                total += temp;
            }
        }
        else {
            odd.push_back(temp);
        }
    }

    sort(odd.rbegin(), odd.rend());
    total += odd[0];

    for(ll i = 1; i < odd.size(); i+=2) {
        if(i+1 >= odd.size()) {
            break;
        }
        if(odd[i] + odd[i+1] > 0) {
            total += odd[i] + odd[i+1];
        }
    }

    cout << total << endl;
}
