#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    int beststreak = 0;

    // Going Forward
    int curr = -1;
    int currerror = -1;
    int streak = 0;
    int streakerror = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] <= currerror) {
            streakerror = streak + 1;
            currerror = curr + 1;
        }
        else {
            streakerror++;
            currerror = v[i];
        }

        if(v[i] <= curr) {
            streak = 1;
        }
        else {
            streak++;
        }
        curr = v[i];

        beststreak = max(streak, beststreak);
        beststreak = max(streakerror, beststreak);
    }

    // Going Backward
    curr = -1;
    currerror = -1;
    streak = 0;
    streakerror = 0;
    for(int i = v.size()-1; i >= 0; i--) {
        if(v[i] >= currerror) {
            streakerror = streak + 1;
            currerror = curr - 1;
        }
        else {
            streakerror++;
            currerror = v[i];
        }

        if(v[i] >= curr) {
            streak = 1;
        }
        else {
            streak++;
        }
        curr = v[i];

        beststreak = max(streak, beststreak);
        beststreak = max(streakerror, beststreak);
    }

    cout << beststreak << endl;
}
