#include <bits/stdc++.h>

using namespace std;

bool opening(char c) {
    if(c == '[' ||
       c == '{' ||
       c == '<' ||
       c == '(') {
        return true;
    }
    return false;
}

bool same(char c1, char c2) {
    if((c1 == '[' && c2 == ']') ||
       (c1 == '{' && c2 == '}') ||
       (c1 == '<' && c2 == '>') ||
       (c1 == '(' && c2 == ')')) {
        return true;
    }
    return false;
}

int main() {
    string s;
    cin >> s;

    stack<char> st;
    int open = 0, cost = 0;
    bool works = true;

    for(auto i : s) {
        if(opening(i)) {
            open++;
            st.push(i);
        }
        else {
            if(open == 0) {
                works = false;
                break;
            }
            open--;
            if(!same(st.top(), i)) {
                cost++;
            }
            st.pop();
        }
    }

    if(!st.empty()) {
        works = false;
    }

    if(works) {
        cout << cost << endl;
    }
    else {
        cout << "Impossible" << endl;
    }
}
