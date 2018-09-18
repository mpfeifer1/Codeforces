#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int soon = 0;
    for(int i = 0; i < n; i++) {
        int s, d;
        cin >> s >> d;

        int here = s;
        while(here <= soon) {
            here += d;
        }

        soon = here;
    }

    cout << soon << endl;
}
