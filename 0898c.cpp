#include <bits/stdc++.h>

using namespace std;

struct node {
    vector<node*> next;
    bool end = false;
};

void insert(node* root, string s) {
    int idx = s.back() - '0';

    bool missing = (root->next[idx] == nullptr);
    if(missing) {
        node* n = new node;
        n->end = true;
        n->next.resize(10, nullptr);
        root->next[idx] = n;
    }

    s.pop_back();
    /*
    if(s.size() == 0) {
        root->next[idx]->end = true;
    }
    */
    if(s.size() > 0) {
        root->next[idx]->end = false;
        insert(root->next[idx], s);
    }
}

void parse(unordered_set<string>& ans, node* root, string prefix) {
    if(root->end) {
        ans.insert(prefix);
        return;
    }

    vector<node*> here = root->next;
    for(int i = 0; i < 10; i++) {
        if(here[i] != nullptr) {
            parse(ans, root->next[i], prefix + char('0'+i));
        }
    }
}

void solve(unordered_set<string>& s) {
    node* tree = new node;
    tree->next.resize(10, nullptr);

    for(auto i : s) {
        insert(tree, i);
    }

    unordered_set<string> ans;
    parse(ans, tree, "");

    cout << ans.size() << " ";
    for(auto i : ans) {
        reverse(i.begin(), i.end());
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    unordered_map<string, unordered_set<string>> m;
    unordered_set<string> allnames;

    while(n--) {
        string name;
        cin >> name;
        allnames.insert(name);

        int nums;
        cin >> nums;

        for(int i = 0; i < nums; i++) {
            string s;
            cin >> s;

            m[name].insert(s);
        }
    }

    cout << allnames.size() << endl;
    for(auto i : allnames) {
        cout << i << " ";
        solve(m[i]);
    }
}
