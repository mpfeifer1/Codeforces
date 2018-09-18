#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int n = min(a,b);

    if(n%2 == 0) {
        cout << "Malvika" << endl;
    }
    else {
        cout << "Akshat" << endl;
    }
}
