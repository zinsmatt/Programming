#include <iostream>
#include <bits/stdc++.h>
 
#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 
 
int main()
{
    int t;
    cin >> t;
   
    
    F(k, t)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int v = 0;
        F(i, n)
        {
            int x;
            cin >> x;
            if (x % 2 == 0)
                a[v++] = x;
        }
        a.resize(v);
        sort(a.begin(), a.end());
        
        ll res = 0;
        unordered_map<int, int> map;
        for (auto x : a)
        {
            while (x % 2 == 0)
            {
                if (map.find(x) != map.end())
                    break;
                map[x] = 1;
                x /= 2;
                ++res;
            }
        }
        cout << res << std::endl;
    }
    
    
    
    
    return 0;
}