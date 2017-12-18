#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if(b > a) {
        swap(a,b);
    }
    int count = 0;
    while(a > 1 && b > 0) {
        count++;
        if(b > a) {
            swap(a,b);
        }
        a -= 2;
        b += 1;
        if(b > a) {
            swap(a,b);
        }
    }

    cout << count << endl;
}
