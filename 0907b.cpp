#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<char>>& v) {
    for(int i = 0; i < 9; i++) {
        if(i == 3 || i == 6) {
            cout << endl;
        }
        for(int j = 0; j < 9; j++) {
            if(j == 3 || j == 6) {
                cout << " ";
            }
            cout << v[i][j];
        }
        cout << endl;
    }
}

int main() {

    vector<vector<char>> v;
    v.resize(9, vector<char>(9));

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(j == 3 || j == 6) {
                cin.ignore();
            }
            cin >> v[i][j];
        }
    }

    int x, y;
    cin >> x >> y;

    x--;
    y--;

    int lox=0, hix=0, loy=0, hiy=0;
    if(x % 3 == 0) {
        lox = 0, hix = 2;
    }
    if(x % 3 == 1) {
        lox = 3, hix = 5;
    }
    if(x % 3 == 2) {
        lox = 6, hix = 8;
    }
    if(y % 3 == 0) {
        loy = 0, hiy = 2;
    }
    if(y % 3 == 1) {
        loy = 3, hiy = 5;
    }
    if(y % 3 == 2) {
        loy = 6, hiy = 8;
    }

    bool found = false;

    for(int i = lox; i <= hix; i++) {
        for(int j = loy; j <= hiy; j++) {
            if(v[i][j] == '.') {
                found = true;
                v[i][j] = '!';
            }
        }
    }

    if(found) {
        print(v);
    }
    else {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(v[i][j] == '.') {
                    v[i][j] = '!';
                }
            }
        }
        print(v);
    }
}
