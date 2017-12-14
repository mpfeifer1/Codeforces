#include <bits/stdc++.h>

using namespace std;

bool distinct(int n) {
    unordered_set<int> s;

    while(n > 0) {
        s.insert(n % 10);
        n /= 10;
    }

    return (s.size() == 4);
}

int main() {
    int n;
    cin >> n;

    n++;
    while(!distinct(n)) {
        n++;
    }

    cout << n << endl;
}
