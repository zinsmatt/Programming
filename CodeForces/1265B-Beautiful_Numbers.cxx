#include <iostream>
#include <bits/stdc++.h>

#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;

using namespace std;


int main()
{
    int t;
    cin >> t;
    
    F(i, t)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> pos(n+1, -1);
        F(j, n)
        {
            cin >> a[j];
            pos[a[j]] = j;
        }
        
        int min = 1e8;
        int max = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (min > pos[j])
                min = pos[j];
            if (max < pos[j])
                max = pos[j];
            if (max - min + 1 == j)
                cout << 1;
            else
                cout << 0;
        }
        cout << std::endl;
    }
    return 0;
}