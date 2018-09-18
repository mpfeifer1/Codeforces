#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, i;
    cin >> n >> i;

    vector<int> v(n);
    for(auto& j : v) {
        cin >> j;
    }

    int total = 0;
    for(auto j : v) {
        if(j >= v[i-1] && j > 0) {
            total++;
        }
    }

    cout << total << endl;
}
