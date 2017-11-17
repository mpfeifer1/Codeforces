#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    ll sum=0, hi=0;

    for(ll i = 0; i < n; i++) {
        ll a;
        cin >> a;

        sum += a;
    }

    vector<int> v;
    for(int i = 0; i < n; i++) {
        ll a;
        cin >> a;

        v.push_back(a);
    }

    sort(v.rbegin(), v.rend());
    hi = v[0] + v[1];

    if(sum <= hi) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
