#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    sort(v.rbegin(), v.rend());

    vector<bool> used(n);

    int total = 0;
    for(int i = 0; i < v.size(); i++) {
        if(!used[i]) {
            total++;
            int size = v[i]-1;
            for(int j = i; j < v.size(); j++) {
                if(v[j] <= size && !used[j]) {
                    used[j] = true;
                    size = v[j]-1;
                }
            }
        }
    }

    cout << total << endl;
}
