#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// String compare and fill in graph
bool compare(string s1, string s2, vector<vector<bool>>& g) {
    int len = min(s1.length(), s2.length());

    for(int i = 0; i < len; i++) {
        if(s1[i] != s2[i]) {
            g[s1[i]-'a'][s2[i]-'a'] = true;
            return true;
        }
    }

    if(s1.length() > s2.length()) {
        return false;
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    // Read input
    vector<string> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    vector<vector<bool>> graph;
    graph.resize(26, vector<bool>(26, false));

    // Build graph, and also check that no words are the same, but not long enough
    bool works = true;
    for(int i = 1; i < v.size(); i++) {
        works &= compare(v[i-1], v[i], graph);
    }

    // If words don't work, quit
    if(!works) {
        cout << "Impossible" << endl;
        return 0;
    }

    // Prepare a toposort
    vector<int> degrees(26,0);
    queue<int> zeroin;
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            if(graph[i][j]) {
                degrees[j]++;
            }
        }
    }

    // Find all with indegree zero
    for(int i = 0; i < 26; i++) {
        if(degrees[i] == 0) {
            zeroin.push(i);
        }
    }

    // Build answer array
    vector<int> ans;

    // Run a toposort
    while(!zeroin.empty()) {
        int curr = zeroin.front();
        zeroin.pop();
        ans.push_back(curr);

        for(int i = 0; i < 26; i++) {
            if(graph[curr][i]) {
                degrees[i]--;
                if(degrees[i] == 0) {
                    zeroin.push(i);
                }
            }
        }
    }

    // Check that the answer works
    if(ans.size() != 26) {
        cout << "Impossible" << endl;
        return 0;
    }

    // Print the answer
    for(auto i : ans) {
        cout << (char)(i + 'a');
    }
    cout << endl;
}
