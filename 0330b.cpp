#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<bool> v(n+1, false);

    for(int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        v[n1] = true;
        v[n2] = true;
    }

    int i;
    for(i = 1; i <= n; i++) {
        if(!v[i]) {
            break;
        }
    }

    cout << n-1 << endl;
    for(int j = 1; j <= n; j++) {
        if(i == j) {
            continue;
        }
        cout << i << " " << j << endl;
    }
}
