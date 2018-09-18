#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> n >> m;

    vector<int> v;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    int c;
    cin >> c;
    int total = 0;
    for(auto i : v) {
        int change = 0;
        int temp = i ^ c;
        while(temp > 0) {
            change += temp & 1;
            temp >>= 1;
        }
        if(change <= m) {
            total++;
        }
    }

    cout << total << endl;
}
