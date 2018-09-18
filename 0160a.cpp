#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    int total = 0;
    int mytotal = 0;
    for(auto& i : v) {
        cin >> i;
        total += i;
    }

    sort(v.begin(), v.end());

    int ct = 0;
    while(mytotal <= total) {
        ct++;
        mytotal += v.back();
        total -= v.back();
        v.pop_back();
    }

    cout << ct << endl;
}
