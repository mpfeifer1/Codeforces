#include <bits/stdc++.h>

using namespace std;

int main() {
    bool works = true;
    int n, k;
    cin >> n >> k;

    int curr = 0;
    int free = 0;
    int count = 0;

    vector<int> v(n);
    for(auto& i : v) {
        cin >> i;
        curr += i;

        // Subtract out "free" money if too much
        if(free + curr > k) {
            free = k - curr;
        }

        // If too much money, quit
        if(curr > k) {
            works = false;
        }

        // If it's a balance check day
        if(i == 0) {

            // If ok amount of money, continue
            if(curr >= 0) {
                continue;
            }

            // If we have enough free money, use it
            if(curr + free >= 0) {
                free += curr;
                curr = 0;
            }

            // If not enough money, add a day
            if(curr < 0) {
                curr = 0;
                free = k;
                count++;
            }
        }
    }

    // Print answer
    if(!works) {
        count = -1;
    }
    cout << count << endl;
}
