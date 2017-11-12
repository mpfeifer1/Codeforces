#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    for(auto& i : v) {
        cin >> i;
    }

    int total = 0;
    for(int i = 1; i < v.size()-1; i++) {
        int l, c, r;
        l = v[i-1];
        c = v[i];
        r = v[i+1];

        if(l > c && c < r) {
            total++;
        }
        if(l < c && c > r) {
            total++;
        }
    }

    cout << total << endl;
}
