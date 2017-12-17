#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int ones = 0;
    for(auto& i : v) {
        cin >> i;
        if(i == 1) {
            ones++;
            i = -1;
        }
        else {
            i = 1;
        }
    }

    int best = -1;
    int curr = 0;
    for(auto i : v) {
        curr += i;
        best = max(best, curr);
        if(curr < 0) {
            curr = 0;
        }

    }

    cout << ones + best << endl;
}
