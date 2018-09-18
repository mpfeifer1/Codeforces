#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    int best = 360;
    for(int i = 0; i < v.size(); i++) {
        int total = 0;
        for(int j = i+1; j < v.size(); j++) {
            total += v[j];
            best = min(best, abs(180 - total) * 2);
        }
    }
    cout << best << endl;
}
