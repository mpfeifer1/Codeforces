#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int n;
    cin >> n;

    int total = 0;
    for(int i = 1; i <= n; i++) {
        if(i % a == 0 ||
           i % b == 0 ||
           i % c == 0 ||
           i % d == 0) {
            total++;
        }
    }

    cout << total << endl;
}
