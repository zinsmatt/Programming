#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    
    int n, m;
    cin >> n >> m;
    
    std::vector<std::pair<int, int>> pairs;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        pairs.emplace_back(std::make_pair(a-1, b-1));
    }
    std::vector<int> xy = {pairs[0].first, pairs[0].second};
    for (auto x : xy)
    {
        std::vector<int> arr(n, 0);
        int all = 0;
        for (auto p : pairs)
        {
            if (p.first != x && p.second != x)
            {
                arr[p.first]++;
                arr[p.second]++;
                ++all;
            }
        }
        
        if (*std::max_element(arr.begin(), arr.end()) == all)
        {
            std::cout << "YES";
            return 0;
        }
    }
    std::cout << "NO";
    
    return 0;
}