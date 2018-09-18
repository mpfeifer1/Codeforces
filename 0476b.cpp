#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll fact[20];

ll choose(ll n, ll k) {
    return fact[n] / (fact[k] * fact[n-k]);
}

int main() {
    // Set up factorial
    fact[0] = 1;
    fact[1] = 1;
    for(ll i = 1; i < 20; i++) {
        fact[i] = i * fact[i-1];
    }

    string s1, s2;
    cin >> s1 >> s2;

    ll target_p = 0;
    ll target_m = 0;

    for(auto i : s1) {
        if(i == '+') {
            target_p++;
        }
        if(i == '-') {
            target_m++;
        }
    }

    ll question = 0;
    for(auto i : s2) {
        if(i == '+') {
            target_p--;
        }
        if(i == '-') {
            target_m--;
        }
        if(i == '?') {
            question++;
        }
    }

    cout << fixed;
    cout.precision(12);

    if(target_p < 0 || target_m < 0) {
        cout << (ld)0 << endl;
        return 0;
    }

    if(target_p == 0 && target_m == 0) {
        cout << (ld)1 << endl;
        return 0;
    }

    // Calc answer here
    ld top = choose(question, target_p);
    ld bot = pow(2, question);

    cout << top / bot << endl;
}
