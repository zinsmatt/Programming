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
        vector<int> a(10);
        int min_i = -1;
        int min_i_val = 1e7;
        F(i, 10)
        {
            cin >> a[i];
            if (i == 0)
                continue;

            if (a[i] < min_i_val)
            {
                min_i = i;
                min_i_val = a[i];
            }
        }
        
        if (a[0] < min_i_val)
        {
            min_i_val = a[0];
            min_i = 0;
        }
        stringstream ss;
        if (min_i == 0)
        {
            ss << "1";
            for (int i = 0; i < min_i_val+1; ++i)
                ss << "0";
        }
        else
        {
            for (int i = 0; i < min_i_val+1; ++i)
                ss << std::to_string(min_i);
        }
        cout << ss.str() << std::endl;
    }
   
 
   
    return 0;
}