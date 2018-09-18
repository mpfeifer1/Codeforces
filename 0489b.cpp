#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> c1(102);
    vector<int> c2(102);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        c1[temp]++;
    }

    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        c2[temp]++;
    }

    int total = 0;

    for(int i = 1; i <= 100; i++) {
        while(c1[i] > 0 && c2[i-1] > 0) {
            c1[i]--;
            c2[i-1]--;
            total++;
        }
        while(c1[i] > 0 && c2[i] > 0) {
            c1[i]--;
            c2[i]--;
            total++;
        }
        while(c1[i] > 0 && c2[i+1] > 0) {
            c1[i]--;
            c2[i+1]--;
            total++;
        }
    }

    cout << total << endl;
}
