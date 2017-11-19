#include <iostream>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int total = 0;

    for(int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        if(n - i < m) {
            total += min(k, temp);
        }
        else {
            total += temp;
        }
    }

    cout << total << endl;
}
