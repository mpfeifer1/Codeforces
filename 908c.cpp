#include <bits/stdc++.h>

using namespace std;

int n, r;

double calc(pair<int,double> curr, int next) {
    return curr.second + sqrt(pow(2*r, 2) - pow(curr.first-next,2));
}

int main() {
    cin >> n >> r;

    vector<pair<int,double>> v;

    int t;
    cin >> t;
    v.push_back({t,r});

    for(int i = 1; i < n; i++) {
        cin >> t;
        double coord = r;
        for(int j = 0; j < i; j++) {
            coord = max(coord, calc(v[j], t));
        }
        v.push_back({t, coord});
    }

    cout << fixed;
    cout.precision(8);
    for(auto i : v) {
        cout << i.second << " ";
    }
    cout << endl;
}
