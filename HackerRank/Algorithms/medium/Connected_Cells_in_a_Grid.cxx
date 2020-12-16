#include <bits/stdc++.h>

using namespace std;

// Complete the connectedCell function below.
// int connectedCell(vector<vector<int>> matrix) {
//     int n = matrix.size();
//     int m = matrix.front().size();
//     vector<vector<bool>> done(n, vector<bool>(m, false));
    
    
//     int res = 0;
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             if (matrix[i][j] && !done[i][j]) {
//                 int size = 0;
//                 // fill
//                 std::queue<pair<int, int>> q;
//                 q.push({i, j});
//                 while (q.size())
//                 {
//                     auto x = q.front();
//                     q.pop();
//                     int xi = x.first;
//                     int xj = x.second;
                    
//                     if (done[xi][xj] == 0)
//                         ++size;
//                     done[xi][xj] = true;
                    
//                     for (int ii = -1; ii <= 1; ++ii) {
//                         for (int jj = -1; jj <= 1; ++jj) {
//                             if (!(ii == 0 && jj == 0) && ii+xi >= 0 && ii+xi < n && jj+xj >= 0 && jj+xj < m && matrix[ii+xi][jj+xj] && !done[ii+xi][jj+xj])
//                                 q.push({ii+xi, jj+xj});
//                         }
//                     }
//                 }
//                 res = max(res, size);
//             }           
//         }
//     }
//     return res;
// }

// Solution with Union-Find (basic version)


pair<int, int> find(const vector<vector<pair<int, int>>>& parents, const pair<int, int>& x)
{
    auto& p = parents[x.first][x.second];
    if (p.first == x.first && p.second == x.second)
        return x;
    else
        return find(parents, p);    
}

void f_union(vector<vector<pair<int, int>>>& parents, vector<vector<int>>& count, const pair<int, int>& a, const pair<int, int>& b)
{
    auto ra = find(parents, a);
    auto rb = find(parents, b);
    if (ra != rb) {
        parents[rb.first][rb.second] = ra;
        count[ra.first][ra.second] += count[rb.first][rb.second];
    }
}

// Complete the connectedCell function below.
int connectedCell(vector<vector<int>> matrix) {
    int n = matrix.size();
    int m = matrix.front().size();
    vector<vector<pair<int, int>>> parents(n, vector<pair<int, int>>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            parents[i][j] = {i, j};
        }
    }
    vector<vector<int>> count = matrix;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 0) continue;
            
            for (int ii = -1; ii <= 1; ++ii) {
                for (int jj = -1; jj <= 1; ++jj) {
                    if (!(ii==0 && jj==0) && ii+i < n && ii+i >= 0 && jj+j < m && jj+j >= 0 && matrix[ii+i][jj+j]) {
                        f_union(parents, count, {i, j}, {ii+i, jj+j});
                    }
                }
            }
        }
    }
    int res = 0;
    for (auto& l: count) {
        res = max(res, *max_element(l.begin(), l.end()));
    }
    return res;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> matrix(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = connectedCell(matrix);

    fout << result << "\n";

    fout.close();

    return 0;
}

