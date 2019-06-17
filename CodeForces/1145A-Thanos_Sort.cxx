#include <iostream>
#include <vector>

int solve(std::vector<int> const& arr, int a, int b)
{
    bool sorted = true;
    if (b-a+1 == 2)
    {
        if (arr[a] < arr[b])
            return 2;
        else
            return 1;
    }
    
    for (int i = a+1; i <= b; ++i)
    {
        if (arr[i] < arr[i-1])
        {
            sorted = false;
            break;
        }
    }
    if (sorted)
        return b-a+1;
    else
    {
        int half = (b-a+1)/2;
        return std::max(solve(arr, a, a+half-1), solve(arr, a+half, b));
    }
}

int main()
{
    int n;
    std::cin >> n;
    
    std::vector<int> arr;
    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;
        arr.push_back(x);
    }
    
    std::cout << solve(arr, 0, arr.size()-1) << std::endl;
    
    return 0;
}