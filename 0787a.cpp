#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    swap(a,b);
    swap(c,d);

    unordered_set<int> s;
    for(int i = a; i < 10000; i+=b) {
        s.insert(i);
    }
    for(int i = c; i < 10000; i+=d) {
        if(s.count(i) > 0) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}
