#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


int find(vector<int>& arr, int x)
{
    if (arr[x] == -1) return x;
    else {
        arr[x] = find(arr, arr[x]);
        return arr[x];
    }
}

long long f_union(vector<int>& arr, int x, int y, vector<long long>& sizes, long long count)
{
    auto root_x = find(arr, x);
    auto root_y = find(arr, y);
    if (root_x != root_y)
    {
        count -= (sizes[root_x]*(sizes[root_x]-1))/2;
        count -= (sizes[root_y]*(sizes[root_y]-1))/2;
        if (sizes[root_x] < sizes[root_y])
        {
            arr[root_x] = root_y;
            sizes[root_y] += sizes[root_x];
            count += (sizes[root_y]*(sizes[root_y]-1))/2;
            
        } else {
            arr[root_y] = root_x;
            sizes[root_x] += sizes[root_y];
            count += (sizes[root_x]*(sizes[root_x]-1))/2;
        }
    }
    return count;
}
void debug(vector<int>& arr, vector<long>& sizes)
{
    std::cout << "arr   : ";
    for (int i = 1; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << "\n";
    std::cout << "sizes : ";
    for (int i = 1; i < sizes.size(); ++i)
        cout << sizes[i] << " ";    
    cout << "\n";
}

// Complete the solve function below.
vector<long long> solve(vector<vector<int>> tree, vector<vector<int>> queries) {
    
    // nlog(n)
    sort(tree.begin(), tree.end(), [](vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    });
    
    vector<int> arr(tree.size()+1+1, -1);
    vector<long long> sizes(tree.size()+1+1, 1);
    std::map<long long, long long> m;
    m[0] = 0;
    
    int i = 0;
    long long count = 0;
    while (i < tree.size())
    {
        int j = i;
        while (i < tree.size() && tree[i][2] == tree[j][2])
        {
            ++i;
        }
        
        for (int k = j; k < i; ++k)
        {
            count = f_union(arr, tree[k][0], tree[k][1], sizes, count);
        }
        
        
//        debug(arr, sizes);
        
        /*long res = 0;
        for (int i = 1; i < arr.size(); ++i)
        {
            if (arr[i] == -1)
            {
                res += sizes[i]*(sizes[i]-1)/2;
            }
        }
        m[tree[j][2]] = res;*/
        
        m[tree[j][2]] = count;
    }
    
    
    vector<long long> res;
    for (int i = 0; i < queries.size(); ++i)
    {
        
        long long l = queries[i][0];
        long long r = queries[i][1];
        
        auto it_left = m.lower_bound(l);
        it_left--;
        auto it_right = m.upper_bound(r);
        it_right--;
        res.push_back(it_right->second - it_left->second);
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nq_temp;
    getline(cin, nq_temp);

    vector<string> nq = split_string(nq_temp);

    int n = stoi(nq[0]);

    int q = stoi(nq[1]);

    vector<vector<int>> tree(n-1);
    for (int tree_row_itr = 0; tree_row_itr < n-1; tree_row_itr++) {
        tree[tree_row_itr].resize(3);

        for (int tree_column_itr = 0; tree_column_itr < 3; tree_column_itr++) {
            cin >> tree[tree_row_itr][tree_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<vector<int>> queries(q);
    for (int queries_row_itr = 0; queries_row_itr < q; queries_row_itr++) {
        queries[queries_row_itr].resize(2);

        for (int queries_column_itr = 0; queries_column_itr < 2; queries_column_itr++) {
            cin >> queries[queries_row_itr][queries_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<long long> result = solve(tree, queries);

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

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

