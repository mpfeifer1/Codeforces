#include <bits/stdc++.h>

using namespace std;

int main() {
    int h1, a1, c1;
    cin >> h1 >> a1 >> c1;
    int h2, a2;
    cin >> h2 >> a2;

    vector<string> log;

    while(h2 > 0) {
        if(h1 <= a2 && h2 > a1) {
            log.push_back("HEAL");
            h1 += c1;
        }
        else {
            log.push_back("STRIKE");
            h2 -= a1;
        }
        h1 -= a2;
    }

    cout << log.size() << endl;
    for(auto i : log) {
        cout << i << endl;
    }
}
