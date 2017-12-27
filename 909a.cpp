#include <bits/stdc++.h>

using namespace std;

int main() {
    string f, l;
    cin >> f >> l;

    string a;
    a.push_back(f[0]);
    for(int i = 1; i < f.size(); i++) {
        if(f[i] < l[0]) {
            a.push_back(f[i]);
        }
        else {
            break;
        }
    }

    a.push_back(l[0]);

    cout << a << endl;
}
