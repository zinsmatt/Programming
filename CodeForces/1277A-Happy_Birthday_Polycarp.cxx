#include <iostream>
#include <bits/stdc++.h>
 
#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 
 
int main()
{
    int n;
    cin >> n;
   
    
    F(k, n)
    {
        string s;
        cin >> s;
        ll res = (s.size() - 1) * 9;
        
        res += (s[0] - '0') - 1;
        bool ok = true;
        for (int j = 1; j < s.size(); ++j)
        {
            if (s[j] < s[0]){
                ok = false;
                break;
            }
            else if (s[j] > s[0])
            {
                ok = true;
                break;
            }
        }
        if (ok)
            ++res;
        cout << res << std::endl;
    }
    
    
    
    
    return 0;
}