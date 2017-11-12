#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;

    int i;
    while(cin >> i) {
        v.push_back(i);
        cin.ignore();
    }

    sort(v.begin(), v.end());

    cout << v[0];
    for(i = 1; i < v.size(); i++) {
        cout << "+" << v[i];
    }
    cout << endl;
}
