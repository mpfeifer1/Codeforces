#include <bits/stdc++.h>

using namespace std;

bool works(int len, int sum) {
    return (sum >= 0 && sum <= len * 9);
}

int main() {
    int n, m;
    cin >> n >> m;

    if(n == 1 && m == 0) {
        cout << "0 0" << endl;
        return 0;
    }

    if(!works(n,m)) {
        cout << "-1 -1" << endl;
        return 0;
    }

    string lo;
    string hi;
    int losum = m;
    int hisum = m;
    bool possible = true;
    for(int i = 0; i < n; i++) {
        // Get min
        for(int j = 0; j <= 9; j++) {
            if(i == 0 && j == 0) {
                continue;
            }
            if(works(n-i-1, losum-j)) {
                lo.push_back(j + '0');
                losum -= j;
                break;
            }
        }

        // Get max
        for(int j = 9; j >= 0; j--) {
            if(i == 0 && j == 0) {
                continue;
            }
            if(works(n-i-1, hisum-j)) {
                hi.push_back(j + '0');
                hisum -= j;
                break;
            }
        }

        if(lo.length() != i+1 || hi.length() != i+1) {
            possible = false;
            break;
        }
    }

    if(possible) {
        cout << lo << " " << hi << endl;
    }
    else {
        cout << "-1 -1" << endl;
    }
}
