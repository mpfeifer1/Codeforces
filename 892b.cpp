#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<ll> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    ll tokill = 0;
    ll killed = 0;
    for(ll i = n-1; i >= 0; i--) {
        if(tokill > 0) {
            killed++;
            tokill--;
        }
        tokill = max(tokill, v[i]);
    }

    cout << n - killed << endl;
}
