#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    vector<int> memo(s.size(), 0);
    for(int i = 1; i < s.size(); i++) {
        memo[i] = memo[i-1];
        if(s[i-1] == s[i]) {
            memo[i]++;
        }
    }

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        cout << memo[n2-1] - memo[n1-1] << endl;
    }
}
