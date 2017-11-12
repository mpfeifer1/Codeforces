#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v(6);

    for(int i = 0; i < 6; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    bool works = false;
    do {
        if(v[0] + v[1] + v[2] == v[3] + v[4] + v[5]) {
            works = true;
        }
    } while(next_permutation(v.begin(), v.end()));

    if(works) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
