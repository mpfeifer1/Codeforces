// Michael Pfeifer
// Version 04, 2018/02/17

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ld  pi   = 4.0*atanl(1.0);
const int iinf = 1e9 + 10;
const ll  inf  = 1e18 + 10;
const int mod  = 1000000007;
const ld  prec = .000001;

#define enld endl
#define endl '\n'
#define pb push_back
#define debug(x) cout<<#x<<" -> "<<x<<'\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define umap unordered_map
#define uset unordered_set

template<class TIn>
using indexed_set = tree<
        TIn, null_type, less<TIn>,
        rb_tree_tag, tree_order_statistics_node_update>;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void file() {
    auto a = freopen("a.in",  "r", stdin);
    auto b = freopen("a.out", "w", stdout);
    if(!a || !b) cout << "uh oh" << endl;
}

void compress(deque<char>& d) {
    while(d.size() > 0 && d.back() == '0') {
        d.pop_back();
    }
    while(d.size() > 0 && d.front() == '0') {
        d.pop_front();
    }
}





/*! The plan to be stored in the output */
struct plan {
    int proposal = 0;
    int revenue = 0;
};

/*! The proposals to be taken in with the input */
struct prop {
    int cost = 0;
    int revenue = 0;
};

/* Function Prototypes */
void print_plans(vector<vector<plan>>& v);
void print_input(vector<vector<prop>>& locations);
void process_input(ifstream& fin, vector<vector<prop>>& locations);
void print_answer(vector<vector<prop>>& p, vector<vector<plan>>& v, int budget, int size);
void capital_dynamic(vector<vector<prop>>& locations, vector<vector<plan>>& v, int budget);
void permute(vector<vector<prop>>& locations, int budget, int location, int cost, int revenue, int& best);
int capital_naive(vector<vector<prop>>& locations, int budget);
int n, m, k;
int beginningcost = 0;



/** @author Michael Pfeifer
 *
 *  @par Description
 *  This function reads in data from the command line,
 *  then launches the capital budgeting program
 *
 *  @param[in]  argc    -   Count of arguments
 *  @param[in]  argv    -   Values of arguments
 *
 *  @returns    [int]   -   Whether the program was successful
 *
 */
int main(int argc, char** argv) {
    cin >> n >> m >> k;
    beginningcost = n*m;

    // Set up location array
    vector<vector<prop>> locations;

    // Read input from the file
    ifstream fin;
    process_input(fin, locations);

    // Print all of the input to make sure it's correct
    //print_input(locations);

    // Get starting budget
    int budget = k;

    // Set up the vector of plans
    vector<vector<plan>> v;
    v.resize(locations.size());

    // Run the capital budgeting (dynamically)
    //auto t1 = chrono::system_clock::now();
    capital_dynamic(locations, v, budget);
    //chrono::duration<double> d1 = chrono::system_clock::now() - t1;

    // Print the dynamic plans after calculating them
    //print_plans(v);

    // Print the dynamic answer
    print_answer(locations, v, budget, locations.size()-1);

    // Run (and print) capital budgeting (naive)
    //auto t2 = chrono::system_clock::now();
    //cout << "Naive: " << capital_naive(locations, budget) << endl << endl;
    //chrono::duration<double> d2 = chrono::system_clock::now() - t2;

    // Print the timings
    //cout << "Dynamic time: " << 1000 * d1.count() << " msec" << endl;
    //cout << "Naive time:   " << 1000 * d2.count() << " msec" << endl;

}



/** @author Michael Pfeifer
 *
 *  @par Description
 *  This function takes in the proposals and plans, as well as the
 *  budget and number of locations. It prints out the best revenue,
 *  and the plan to achieve it
 *
 *  @param[in]  p       -   The array of propositions
 *  @param[in]  v       -   The array of plans
 *  @param[in]  budget  -   The initially given budget
 *  @param[in]  size    -   The total number of locations
 *
 *  @returns None
 *
 */
void print_answer(vector<vector<prop>>& p, vector<vector<plan>>& v, int budget, int size) {
    cout << max(beginningcost - v[size][budget].revenue, 0) << endl;

    // Get plan
    //vector<int> answer;
    //for(int i = size; i >= 0; i--) {
    //    plan current = v[i][budget];
    //    answer.push_back(current.proposal);
    //    budget -= p[i][current.proposal].cost;
    //}

    // Reverse the answer because the traversal goes last to first
    //reverse(answer.begin(), answer.end());

    // Print out full plan
    //for(unsigned int i = 0; i < answer.size(); i++) {
    //    cout << "Location " << i+1 << ": Plan " << answer[i]+1 << endl;
    //}
    //cout << endl;
}



/** @author Michael Pfeifer
 *
 *  @par Description
 *  This function prints each location and its
 *  proposals after they have been read in from
 *  the file
 *
 *  @param[in]  locations   -   The array of locations and propostions
 *
 *  @returns None
 *
 */
void print_input(vector<vector<prop>>& locations) {
    // Print the locations after they've been read in
    cout << "Input" << endl;
    for(unsigned int i = 0; i < locations.size(); i++) {
        cout << "Location " << i+1 << ": " << endl;

        for(auto prop : locations[i]) {
            cout << prop.cost << " " << prop.revenue << endl;
        }
    }
    cout << endl;
}



/** @author Michael Pfeifer
 *
 *  @par Description
 *  This function prints out the plan for each
 *  location given any budget after it has been
 *  calculated by the dynamic solution
 *
 *  @param[in]  v   -   The array of plans
 *
 *  @returns None
 *
 */
void print_plans(vector<vector<plan>>& v) {
    // Print out every plan after they've been created
    cout << "Dynamic Tables" << endl;
    for(unsigned int i = 0; i < v.size(); i++) {
        cout << "Location " << i+1 << ": " << endl;

        for(unsigned int j = 0; j < v[i].size(); j++) {
            cout << j << " " << v[i][j].proposal+1 << " " << v[i][j].revenue << endl;
        }
    }
    cout << endl;
}



/** @author Michael Pfeifer
 *
 *  @par Description
 *  This function launches the naive capital budgeting solution
 *
 *  @param[in]  locations   -   The array of proposals
 *  @param[in]  budget      -   The initially given budget
 *
 *  @returns    [int]       -   The maximum revenue you can earn
 *
 */
int capital_naive(vector<vector<prop>>& locations, int budget) {
    // Launch the capital budgeting naive solution
    int best = 0;
    permute(locations, budget, 0, 0, 0, best);
    return best;
}



/** @author Michael Pfeifer
 *
 *  @par Description
 *  This function solves capital budgeting naively. It
 *  runs a brute force by attempting every possible combination,
 *  and quits as it runs out of money
 *
 *  @param[in]      locations   -   Count of arguments
 *  @param[in]      location    -   Index of the current location
 *  @param[in]      budget      -   The initially given budget
 *  @param[in]      cost        -   The current amount spent
 *  @param[in]      revenue     -   The current amount mane
 *  @param[in][out] best        -   The best revenue achieved so far
 *
 *  @returns None
 *
 */
void permute(vector<vector<prop>>& locations, int budget, int location, int cost, int revenue, int& best) {
    // Base case
    if(location == (signed)locations.size()) {
        return;
    }

    // For each location here
    for(auto i : locations[location]) {
        // If over budget, quit
        if(cost + i.cost > budget) {
            continue;
        }

        // Otherwise, try this place
        if(revenue + i.revenue > best) {
            best = revenue + i.revenue;
        }
        permute(locations, budget, location+1, cost + i.cost, revenue + i.revenue, best);
    }
}



/** @author Michael Pfeifer
 *
 *  @par Description
 *  This function runs the capital budgeting
 *  solution using dynamic programming. It calculates
 *  the best for every possible budget at every location
 *
 *  @param[in]      locations   -   The array of proposals
 *  @param[in][out] v           -   The array of plans to return
 *  @param[in]      budget      -   The initially given budget
 *
 *  @returns None
 *
 */
void capital_dynamic(vector<vector<prop>>& locations, vector<vector<plan>>& v, int budget) {
    // For each location
    for(unsigned int i = 0; i < v.size(); i++) {
        for(int j = 0; j <= budget; j++) {
            // Create an empty plan
            plan best;
            best.proposal = 0;
            best.revenue = 0;

            // Find the best plan
            for(unsigned int k = 0; k < locations[i].size(); k++) {
                // Construct this plan
                prop proposal = locations[i][k];

                plan temp;
                temp.proposal = k;

                // If first row,
                if(i == 0) {
                    if(proposal.cost > j) {
                    }
                    else {
                        temp.revenue = proposal.revenue;
                    }
                }

                // Second row or later
                else {
                    // If we can't take this proposal
                    if(proposal.cost > j) {
                        temp.revenue = v[i-1][j].revenue;
                    }

                    // If we can,
                    else {
                        // Use it or not, whichever is better
                        temp.revenue = max(proposal.revenue + v[i-1][j-proposal.cost].revenue, v[i-1][j].revenue);
                    }
                }

                // Set it if it's the best plan
                if(temp.revenue > best.revenue) {
                    best = temp;
                }
            }

            // Add the best plan
            v[i].push_back(best);
        }
    }
}



/** @author Michael Pfeifer
 *
 *  @par Description
 *  This function reads in all the data from the command line,
 *  and stores it in locations
 *
 *  @param[in]  fin         -   The file to read from
 *  @param[in]  locations   -   The list of proposals to fill in
 *
 *  @returns None
 *
 */
void process_input(ifstream& fin, vector<vector<prop>>& locations) {
    // Build location data
    int num_locations = n;
    for(int i = 0; i < num_locations; i++) {
        string s;
        cin >> s;
        deque<char> d;
        int ones = 0;
        int zero = 0;
        for(auto i : s) {
            d.pb(i);
            if(i == '1') {
                ones++;
            }
            else {
                zero++;
            }
        }

        // Start a list of propositions for each location with {0,0}
        prop p;
        p.cost = 0;
        p.revenue = 0;

        vector<prop> l(ones+1, p);
        for(int i = 0; i < l.size(); i++) {
            l[i] = {i, 0};
        }

        int onesleft = ones;
        int zeroleft = zero;

        for(int i = 0; i < d.size(); i++) {
            // Prep state for inner loop
            int t_onesleft = onesleft;
            int t_zeroleft = zeroleft;

            for(int j = d.size()-1; j >= i-1; j--) {
                // Save state
                int costhere = ones - t_onesleft;
                int revhere = d.size() - (j - i + 1);

                l[costhere].revenue = max(l[costhere].revenue, revhere);

                if(j < 0) {
                    continue;
                }

                // Move in
                if(d[j] == '1') {
                    t_onesleft--;
                }
                else {
                    t_zeroleft--;
                }
            }

            // Move in
            if(d[i] == '1') {
                onesleft--;
            }
            else {
                zeroleft--;
            }
        }

        // Add the location to the list of locations
        locations.push_back(l);
    }
}
