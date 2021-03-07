#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the minimumAverage function below.
 */
long long minimumAverage(vector<vector<long long>> customers) {
    /*
     * Write your code here.
     */
     
    std::sort(customers.begin(), customers.end(), [](const std::vector<long long> a, const std::vector<long long>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    });
    
    long long t = 0;
    int i = 0;
    
    auto cmp = [](const vector<long long>& a, const vector<long long>& b) { 
        if (a[1] == b[1]) return a[0] > b[0];
        return a[1] > b[1];
    };

    std::priority_queue<std::vector<long long>, std::vector<std::vector<long long>>, decltype(cmp)> q(cmp);
    long long tot = 0;
    while (i < customers.size() || !q.empty()) {
        while (i < customers.size() && customers[i][0] <= t) {
            q.push(customers[i++]);
        }
        if (!q.empty()) {
            auto cur = q.top();
            q.pop();
            t += cur[1];
            tot += t-cur[0];
        } else if (i < customers.size()) {
            t = customers[i][0];
            q.push(customers[i++]);
        } 
    }
    return tot / customers.size();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<long long>> customers(n);
    for (int customers_row_itr = 0; customers_row_itr < n; customers_row_itr++) {
        customers[customers_row_itr].resize(2);

        for (int customers_column_itr = 0; customers_column_itr < 2; customers_column_itr++) {
            cin >> customers[customers_row_itr][customers_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long long result = minimumAverage(customers);

    fout << result << "\n";

    fout.close();

    return 0;
}

