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
        int x=0, y=0, z=0, w=0;
        vector<int> iy, iz;
        unordered_map<string, int> mapy;
        unordered_map<string, int> mapz;
        F(i, n)
        {
            string s;
            cin >> s;
            //ss[i] = s;
            char l = s[0];
            char r = s[s.size()-1];
            if (r == l)
            {
                if (r == '0')
                    ++x;
                else
                    ++w;
            }
            else
            {
                if (l == '0')
                {
                    ++y;
                    mapy[s] = 1+i;
                }
                else
                {
                    ++z;
                    mapz[s] = 1+i;
                }
            }
        }
        //cout << x << " " << y << " " << z << " " << w << std::endl;
 
        int res = max(abs(y-z)/2, 0);
        if (y+z == 0 and x > 0 and w > 0)
            cout << "-1\n";
        else
        {
            if (res == 0)
                cout << "0\n\n";
            else
            {
                if (y < z)
                {
                    vector<int> good;
                    for (auto& p : mapz)
                    {
                        string sr = p.first;
                        reverse(sr.begin(), sr.end());
                        if (mapy.find(sr) == mapy.end())
                        {
                            good.push_back(p.second);
                        }
                        if (good.size() == res)
                            break;
                    }
                    if (good.size() == res)
                    {
                        cout << res << "\n";
                        for (auto g : good)
                            cout << g << " ";
                        cout << std::endl;
                    }
                    else
                    {
                        cout << "-1\n";
                    }
                }
                else
                {
                   vector<int> good;
                    for (auto& p : mapy)
                    {
                        string sr = p.first;
                        reverse(sr.begin(), sr.end());
                        if (mapz.find(sr) == mapz.end())
                        {
                            good.push_back(p.second);
                        }
                        if (good.size() == res)
                            break;
                    }
                    if (good.size() == res)
                    {
                        cout << res << "\n";
                        for (auto g : good)
                            cout << g << " ";
                        cout << std::endl;
                    }
                    else
                    {
                        cout << "-1\n";
                    }
                }
            }
        }
    }
    
    
    
    return 0;
}