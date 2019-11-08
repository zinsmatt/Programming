#include <bits/stdc++.h>

using namespace std;

int pgcd(int a, int b)
{
    if (a > b)
        swap(a, b);
        
    int r = 1;
    while (r != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int q;
    
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1 || b == 1 || pgcd(a, b) == 1)
        {
            cout << "Finite\n";
        }
        else
        {
            cout << "Infinite\n";
        }
        
    }
    
    
    return 0;
}