#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    
    int n;
    cin >> n;
    std::vector<int> arr(n);
    long s = 0;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        arr[i] = a;
        s += a;
    }
    long t = 0;
    int index = n;
    for (int i = 0; i < n; ++i)
    {
        t += arr[i];
        if (t * 2 >= s)
        {
            index = i + 1;
            break;
        }
    }
    std::cout << index << "\n";
    
    return 0;
}