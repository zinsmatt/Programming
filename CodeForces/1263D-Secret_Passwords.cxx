#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<int> col(26, -1);
    int nouv = 0;
    for (int q = 0; q < n; ++q)
    {
        std::string s;
        cin >> s;
        vector<int> occ(26, 0);
        vector<int> uni;
        for (auto& c : s)
        {
            int x = c - 'a';
            if (occ[x] == 0)
                uni.push_back(x);
            occ[x] = 1;
        }
        
        vector<int> used_col;
        for (int iu = 0; iu < uni.size(); ++iu)
        {
            if (col[uni[iu]] != -1)
            {
                used_col.push_back(col[uni[iu]]);
            }
            col[uni[iu]] = nouv;
        }
        for (auto u : used_col)
        {
            for (int i = 0; i < 26; ++i)
            {
                if (col[i] == u)
                    col[i] = nouv;
            }
        }
        nouv++;
    }
    
    unordered_map<int, int> occ;
    int res = 0;
    for (int& c : col)
    {
        // std::cout << c << "\n";
        if (c != -1)
        {
            if (occ.find(c) == occ.end())
            {
                ++res;
                occ[c] = 1;
            }
        }
    }
    
    cout << res;
    
    return 0;
}