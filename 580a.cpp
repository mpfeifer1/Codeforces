#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<ll> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    int val = v[0];
    int len = 1;
    int bestlen = 1;

    for(int i = 1; i < v.size(); i++) {
        if(v[i] >= val) {
            len++;
        }
        else {
            len = 1;
        }
        bestlen = max(len, bestlen);
        val = v[i];
    }

    cout << bestlen << endl;
}
