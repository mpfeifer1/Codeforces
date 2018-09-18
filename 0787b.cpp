#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    bool allgood = true;
    for(int i = 0; i < m; i++) {
        bool thisgood = false;

        int count;
        cin >> count;

        unordered_set<int> here;
        for(int j = 0; j < count; j++) {
            int temp;
            cin >> temp;
            if(here.count(-temp) > 0) {
                thisgood = true;
            }
            here.insert(temp);
        }

        allgood &= thisgood;
    }

    if(allgood) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }
}
