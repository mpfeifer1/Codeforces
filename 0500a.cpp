#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    n--;
    m--;

    vector<int> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    int c = 0;
    while(c <= n) {
        if(c == m) {
            cout << "YES" << endl;
            return 0;
        }

        c += v[c];

        if(c > m) {
            break;
        }
    }

    cout << "NO" << endl;
}
