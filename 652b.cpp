#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    sort(v.begin(), v.end());

    auto b = v.begin();
    auto e = v.end();
    while(b < e) {
        cout << *b << " ";
        b++;

        if(b >= e) {
            break;
        }

        e--;
        cout << *e << " ";
    }
    cout << endl;
}
