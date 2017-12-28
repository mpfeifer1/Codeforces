#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;

    int best = 0;

    for(int i = 1; i < n; i++) {
        int actuala = i;
        int actualb = n-i;

        if(actuala > a || actualb > b) {
            continue;
        }

        best = max(best, min(a/actuala, b/actualb));
    }

    cout << best << endl;
}
