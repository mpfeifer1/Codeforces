#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int inf = 2 << 28;

int main() {
    int curr, goal;
    cin >> curr >> goal;

    int size = max(curr, goal) * 2 + 1;
    vector<int> v(size, inf);

    v[curr] = 0;
    queue<int> q;
    q.push(curr);

    while(!q.empty()) {
        int n = q.front();
        q.pop();

        int doub = n * 2;
        if(doub < size && v[doub] > v[n] + 1) {
            v[doub] = v[n] + 1;
            q.push(doub);
        }

        int back = n - 1;
        if(back >= 0 && v[back] > v[n] + 1) {
            v[back] = v[n] + 1;
            q.push(back);
        }
    }

    cout << v[goal] << endl;
}
