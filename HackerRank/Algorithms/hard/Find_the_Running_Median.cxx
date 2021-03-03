#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the runningMedian function below.
 */
vector<double> runningMedian(vector<int> a) {
    /*
     * Write your code here.
     */
     
    std::multiset<long> S;
    vector<double> res;
    std::multiset<long>::iterator it;
    for (int i = 0; i < a.size(); ++i)
    {
        if (i == 0) {
            S.insert(a[i]);
            it = S.begin();
        } else {
            S.insert(a[i]);
            if (S.size() % 2 == 0)
            {
                if (a[i] >= *it)
                    ++it;
            } else {
                if (a[i] < *it)
                    --it;
            }
        }
        
        if (S.size() % 2) {
            res.push_back(*it);            
        } else {
            auto it2 = it;
            --it2;
            res.push_back(static_cast<double>(*it + *it2) / 2);
        }
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int a_count;
    cin >> a_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> a(a_count);

    for (int a_itr = 0; a_itr < a_count; a_itr++) {
        int a_item;
        cin >> a_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        a[a_itr] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

