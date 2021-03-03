#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define VPRINT(name, v) \
    cout << name << " : "; \
    for (auto& e : v) { \
        cout << e << " "; \
    } \
    cout << std::endl; \

int find(vector<int>& arr, int x)
{
    if (arr[x] == -1) return x;
    else {
        arr[x] = find(arr, arr[x]);
        return arr[x];
    }
}

void f_union(vector<int>& arr, int x, int y, vector<long long>& sizes)
{
    auto root_x = find(arr, x);
    auto root_y = find(arr, y);
    if (root_x != root_y)
    {
        if (sizes[root_x] < sizes[root_y]) {
            arr[root_x] = root_y;
            sizes[root_y] += sizes[root_x];
        } else {
            arr[root_y] = root_x;
            sizes[root_x] += sizes[root_y];
        }
    }
}

void debug(vector<int>& arr, vector<long long>& sizes)
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


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<vector<int>> reds, blacks;
    for (int i = 0; i < n-1; ++i)
    {
        int x, y;
        char c;
        cin >> x >> y >> c;
        if (c == 'r') {
            reds.push_back({x, y});
        } else {
            blacks.push_back({x, y});
        }
    }
    
    vector<int> arr(n+1, -1);
    vector<long long> sizes(n+1, 1);
    for (auto& v : blacks) {
        f_union(arr, v[0], v[1], sizes);
    }
    
    //debug(arr, sizes);
    
    vector<int> sets;
    vector<long long> sets_sizes;
    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i] == -1) {
            sets.push_back(i);
            sets_sizes.push_back(sizes[i]);
        }
    }
    
    // No need to use the red edges because the structure is a tree, meaning that there exist a unique path
    // made of red edges between each pair of disjoint components.
    // Just compute the sum of size[i]*size[j]*size[k] for each triplet (i, j, k)
        
    long long res = 0;
      
    // Factorize the triple sum of products to be in O(n)
    vector<long long> K(sets.size(), 0);
    K.back() = sets_sizes.back();
    for (int k = K.size()-2; k >= 0; --k)
    {
        K[k] = K[k+1] + sets_sizes[k];
    }

    vector<long long> J(K.size(), 0);
    J[J.size()-2] = sets_sizes[J.size()-2] * K[J.size()-1];
    for (int j = J.size()-3; j >= 0; --j)
    {
        J[j] = J[j+1] + sets_sizes[j] * K[j+1];
    }
    
    for (int i = 0; i < J.size()-1; ++i) {
        res += sets_sizes[i] * J[i+1];
    }
    
    
    // trivial O(n^3) solution
    /*for (int i = 0; i < sets.size(); ++i) {
        for (int j = i+1; j < sets.size(); ++j) {
            for (int k = j+1; k < sets.size(); ++k) {
                int a = sets[i], b = sets[j], c = sets[k];
                res += sizes[a] * sizes[b] * sizes[c];   
            }
        }
    }*/
    
    std::cout << res % 1000000007ll << "\n";
    
    return 0;
}

