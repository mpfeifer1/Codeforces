#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> memo(110, false);
    memo[0] = true;

    for(int i = 0; i <= 100; i++) {
        if(memo[i]) {
            memo[i+7] = true;
        }
        if(memo[i]) {
            memo[i+3] = true;
        }
    }

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        if(memo[temp]) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
