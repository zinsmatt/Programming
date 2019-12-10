#include <iostream>
#include <bits/stdc++.h>

#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;

using namespace std;


int main()
{

    int t;
    cin >> t;
    
    F(tt, t)
    {
        string s;
        cin >> s;
        vector<int> odd, even;
        for (auto& c : s)
        {
            int x = static_cast<int>(c - '0');
            if (x % 2 == 0)
            {
                even.push_back(x);
            }
            else
            {
                odd.push_back(x);
            }
        }
        int i_odd = 0, i_even = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (i_even == even.size() || i_odd < odd.size() && odd[i_odd] < even[i_even])
            {
                cout << odd[i_odd++];
            }
            else
            {
                cout << even[i_even++];
            }
        }
        cout << std::endl;
        
        
    }
    return 0;
}