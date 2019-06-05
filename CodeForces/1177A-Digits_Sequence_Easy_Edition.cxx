#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    
    int n;
    cin >> n;
    int a  = 0;
    int x = 1;
    while (a != n)
    {
        for (char& c : std::to_string(x))
        {
            ++a;
            if (a == n)
            {
                std::cout << c;
                return 0;
            }
        }
        ++x;
    }
    
    
    return 0;
}