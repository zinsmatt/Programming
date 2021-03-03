#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int find(vector<int>& arr, int x)
{
    if (arr[x] == -1) return x;
    else {
        arr[x] = find(arr, arr[x]);
        return arr[x];
    }
}

void f_union(vector<int>& arr, int x, int y, vector<int>& sizes)
{
    auto root_x = find(arr, x);
    auto root_y = find(arr, y);
    if (root_x != root_y) {
        if (sizes[root_y] > sizes[root_y]) {
            arr[root_x] = root_y;
            sizes[root_y] += sizes[root_x];
        } else {
            arr[root_y] = root_x;
            sizes[root_x] += sizes[root_y];
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int n, q;
    cin >> n >> q;
    vector<int> arr(n, -1);
    vector<int> sizes(n, 1);
    
    for (int i = 0; i < q; ++i)
    {
        char op;
        cin >> op;
        if (op == 'M') {
            int a, b;
            cin >> a >> b;
            f_union(arr, a, b, sizes);
        } else {
            int a;
            cin >> a;
            auto s = sizes[find(arr, a)];
            std::cout << s << "\n";
        }
    }   
    return 0;
}

