#include <iostream>
#include <vector>

using namespace std;

int process(vector<int>& v, int i) {
    int total = 0;
    while(v[i] >= 0) {
        total++;
        i = v[i];
    }
    return total;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    for(auto& i : v) {
        cin >> i;
        i--;
    }

    int best = 0;
    for(int i = 0; i < v.size(); i++) {
        best = max(best, process(v, i));
    }

    cout << best+1 << endl;
}
