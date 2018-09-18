#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(auto& i : v) {
        cin >> i;
        i--;
    }

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        a[v[i]] = i;
    }

    for(auto i : a) {
        cout << i+1 << " ";
    }
    cout << endl;
}
