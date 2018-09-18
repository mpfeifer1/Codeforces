#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    vector<int> v(3);
    for(auto& i : v) {
        cin >> i;
    }

    sort(v.begin(), v.end());
    if(v[0] == 1) {
        cout << "YES" << endl;;
        return 0;
    }

    int start1=-1;
    int start2=-1;

    int other1=-1;
    int other2=-1;

    bool works1 = true;
    bool works2 = true;

    for(int i = v[0]; i <= 5000*5000; i++) {
        if(i % v[0] != 0) {
            if(start1 == -1) {
                start1 = i;
            }
            else if((i - start1) % v[1] != 0 && start2 == -1) {
                start2 = i;
            }
            else if((i - start1) % v[1] != 0 && (i - start2) % v[2] != 0) {
                works1 = false;
            }
        }

        if(i % v[0] != 0) {
            if(other1 == -1) {
                other1 = i;
            }
            else if((i - other1) % v[2] != 0 && other2 == -1) {
                other2 = i;
            }
            else if((i - other1) % v[2] != 0 && (i - other2) % v[1] != 0) {
                works2 = false;
            }
        }
    }

    if(works1 || works2) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
