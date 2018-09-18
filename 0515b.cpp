#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> b(n, false);
    vector<int> g(m, false);

    int n1;
    cin >> n1;
    for(int i = 0; i < n1; i++) {
        int temp;
        cin >> temp;
        b[temp] = true;
    }

    int n2;
    cin >> n2;
    for(int i = 0; i < n2; i++) {
        int temp;
        cin >> temp;
        g[temp] = true;
    }

    for(int i = 0; i < 100001; i++) {
        b[i%n] |= g[i%m];
        g[i%m] |= b[i%n];
    }

    bool works = true;
    for(auto i : b) {
        works &= i;
    }
    for(auto i : g) {
        works &= i;
    }

    if(works) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
