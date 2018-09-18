#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int solve(int n, vector<int> needed) {
    int leftover = 0;
    int cost = 0;

    for(auto i : needed) {
        if(leftover - i < 0) {
            leftover = n;
            cost++;
        }
        leftover -= i;
    }

    return cost;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> needed;
    needed.push_back(a);
    needed.push_back(a);
    needed.push_back(a);
    needed.push_back(a);
    needed.push_back(b);
    needed.push_back(b);

    sort(needed.begin(), needed.end());

    int best = 7;
    do {
        best = min(best, solve(n, needed));
    } while(next_permutation(needed.begin(), needed.end()));

    cout << best << endl;
}
