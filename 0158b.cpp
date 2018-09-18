#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(5, 0);

    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;
        v[m]++;
    }

    int total = v[4];

    while(v[3] > 0 || v[2] > 0 || v[1] > 0) {
        total++;

        if(v[3] > 0) {
            v[3]--;
            if(v[1] > 0) {
                v[1]--;
            }
            continue;
        }

        if(v[2] > 0) {
            v[2]--;
            if(v[2] > 0) {
                v[2]--;
                continue;
            }
            if(v[1] > 0) {
                v[1]--;
            }
            if(v[1] > 0) {
                v[1]--;
            }
            continue;
        }

        if(v[1] > 0) {
            v[1] -= 4;
        }
    }

    cout << total << endl;
}
