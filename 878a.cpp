#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<char> v(10, 'i');

    int n;
    cin >> n;

    // Read old commands
    for(int i = 0; i < n; i++) {
        char op;
        int num;
        cin >> op >> num;

        int pos = 0;
        while(pos < 10) {
            bool bit = (num % 2 != 0);
            if(op == '|' && bit) {
                v[pos] = '1';
            }
            if(op == '&' && !bit) {
                v[pos] = '0';
            }
            if(op == '^' && bit) {
                if(v[pos] == 'i') {
                    v[pos] = 'n';
                }
                else if(v[pos] == 'n') {
                    v[pos] = 'i';
                }
                else if(v[pos] == '1') {
                    v[pos] = '0';
                }
                else if(v[pos] == '0') {
                    v[pos] = '1';
                }
            }

            num >>= 1;
            pos++;
        }
    }

    // Build new commands
    int xr = 0;
    int nd = 0;
    int rr = 0;
    int mask = 1;
    for(int i = 0; i < 10; i++) {
        if(v[i] != '0') {
            nd += mask;
        }
        if(v[i] == '1') {
            rr += mask;
        }
        if(v[i] == 'n') {
            xr += mask;
        }

        mask <<= 1;
    }

    // Print new commands
    cout << "3" << endl;
    cout << "^ " << xr << endl;
    cout << "| " << rr << endl;
    cout << "& " << nd << endl;
}
