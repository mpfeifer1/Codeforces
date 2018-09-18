#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;

    int lo = (ll)10000000000;
    vector<int> loc;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        if(temp < lo) {
            lo = temp;
            loc.clear();
            loc.push_back(i);
        }
        else if(temp == lo) {
            loc.push_back(i);
        }
    }

    int lodist = (ll)10000000000;
    for(int i = 1; i < loc.size(); i++) {
        lodist = min(lodist, loc[i] - loc[i-1]);
    }

    cout << lodist << endl;
}
