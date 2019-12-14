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
        int l = 0;
        vector<int> a, b;
        for (int i = 0; i < s.size(); ++i)
        {
            if (i < s.size()-2)
            {
                const auto& ss = s.substr(i, 3);
                if (ss == "one")
                    b.push_back(i);
                if (ss == "two")
                    a.push_back(i);
            }
        }
        int aa=0 ,bb = 0;
        //cout << "a.size " << a.size() << std::endl;
        //cout << "b.size " << b.size() << std::endl;
        vector<int> to_rem;
        while (aa < a.size() || bb < b.size())
        {
            if (bb == b.size())
            {
                to_rem.push_back(a[aa++]+1);
            }
            else if (aa == a.size())
            {
                to_rem.push_back(b[bb++]+1);
            }
            else if (a[aa] < b[bb])
            {
                if (a[aa] + 2 == b[bb])
                {
                    to_rem.push_back(a[aa]+2);
                    ++bb;
                    ++aa;
                }
                else
                {
                    to_rem.push_back(a[aa++]+1);
                }
            }
            else
            {
                to_rem.push_back(b[bb++]+1);
            }
        }
        cout << to_rem.size() << "\n";
        for (auto r : to_rem)
            cout << r+1 << " ";
        cout << std::endl;
    }
    
    
    
    
    return 0;
}