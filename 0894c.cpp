#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    // Read input
    vector<int> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    // Get GCD of all
    int num = v[0];
    for(int i = 1; i < v.size(); i++) {
        num = __gcd(num, v[i]);
    }

    // Check we have GCD
    if(v[0] != num) {
        cout << "-1" << endl;
        return 0;
    }

    // Print all elements with the GCD between each
    cout << v.size()*2-1 << endl;
    cout << v[0];
    for(int i = 1; i < v.size(); i++) {
        cout << " " << v[0] << " " << v[i];
    }
    cout << endl;
}
