#include <bits/stdc++.h>

using namespace std;

int ceildiv(int top, int bot) {
    return (top + bot - 1) / bot;
}

int main() {
    int n;
    cin >> n;
    cout << ceildiv(n, 5) << endl;
}
