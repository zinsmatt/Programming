#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int res = 0;
    int i = 1;
    while (n > 0)
    {
        n--;
        if (i % m == 0)
            ++n;
        ++i;
    }
    cout << i-1;
    
    return 0;
}