#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>& d, int a) {
    if(d[a] == -1) {
        return a;
    }

    d[a] = find(d, d[a]);
    return d[a];
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);

    if(a == b) {
        return;
    }

    d[a] = b;
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n, -1);

    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        t--;

        join(v, i, t);
    }

    int total = 0;
    for(auto i : v) {
        if(i == -1) {
            total++;
        }
    }

    cout << total << endl;
}
