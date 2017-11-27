#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<bool> v(5, false);
    for(auto i : s) {
        if(i == 'o' && v[3]) {
            v[4] = true;
        }
        if(i == 'l' && v[2]) {
            v[3] = true;
        }
        if(i == 'l' && v[1]) {
            v[2] = true;
        }
        if(i == 'e' && v[0]) {
            v[1] = true;
        }
        if(i == 'h') {
            v[0] = true;
        }
    }

    if(v[4]) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
