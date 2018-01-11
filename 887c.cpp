#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int> v) {
    bool works = true;
    works &= (v[0]  == v[1]);
    works &= (v[1]  == v[2]);
    works &= (v[2]  == v[3]);

    works &= (v[4]  == v[5]);
    works &= (v[5]  == v[6]);
    works &= (v[6]  == v[7]);

    works &= (v[8]  == v[9]);
    works &= (v[9]  == v[10]);
    works &= (v[10] == v[11]);

    works &= (v[12] == v[13]);
    works &= (v[13] == v[14]);
    works &= (v[14] == v[15]);

    works &= (v[16] == v[17]);
    works &= (v[17] == v[18]);
    works &= (v[18] == v[19]);

    works &= (v[20] == v[21]);
    works &= (v[21] == v[22]);
    works &= (v[22] == v[23]);

    return works;
}

vector<int> u(vector<int> v) {
    int a = v[4];
    int b = v[5];
    v[4]  = v[16];
    v[5]  = v[17];
    v[16] = v[20];
    v[17] = v[21];
    v[20] = v[12];
    v[21] = v[13];
    v[12] = a;
    v[13] = b;

    return v;
}

vector<int> l(vector<int> v) {
    int a = v[0];
    int b = v[2];
    v[0]  = v[4];
    v[2]  = v[6];
    v[4]  = v[8];
    v[6]  = v[10];
    v[8]  = v[23];
    v[10] = v[21];
    v[23] = a;
    v[21] = b;

    return v;
}

vector<int> f(vector<int> v) {
    int a = v[2];
    int b = v[3];
    v[2]  = v[16];
    v[3]  = v[18];
    v[16] = v[9];
    v[18] = v[8];
    v[9] = v[15];
    v[8]  = v[13];
    v[15] = a;
    v[13] = b;

    return v;
}

int main() {
    vector<int> v(24);
    for(auto& i : v) {
        cin >> i;
    }

    bool works = false;
    works |= solve(u(v));
    works |= solve(u(u(u(v))));
    works |= solve(l(v));
    works |= solve(l(l(l(v))));
    works |= solve(f(v));
    works |= solve(f(f(f(v))));

    if(works) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
