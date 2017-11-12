#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(5, 0);

    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;
        v[m]++;
    }

    int total = v[4];

    total[4] += total[3];
    total[1] -= total[3];
    total[1] = max(total[1], 0);
    total[4] += total[3];
    total[3] = 0;

    cout << total << endl;
}
