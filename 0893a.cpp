#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> v;
    v = {true, true, false};
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        if(temp == 1) {
            if(!v[0]) {
                cout << "NO" << endl;
                return 0;
            }
            swap(v[2], v[1]);
        }
        if(temp == 2) {
            if(!v[1]) {
                cout << "NO" << endl;
                return 0;
            }
            swap(v[0], v[2]);
        }
        if(temp == 3) {
            if(!v[2]) {
                cout << "NO" << endl;
                return 0;
            }
            swap(v[0], v[1]);
        }
    }

    cout << "YES" << endl;
}
