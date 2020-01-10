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

    
    vector<int> res(t);
    vector<pair<int, int>> neg, pos;
    F(i, t)
    {
        int x;
        cin >> x;
        if (x % 2 == 0)
            res[i] = x / 2;
        else
        {
            if (x < 0)
            {
                neg.push_back(make_pair(i, x));
            }
            else
            {
                pos.push_back(make_pair(i, x));
            }
        }
    }

    bool state = false;
    for (auto &p : neg)
    {
        if (state)
        {
            res[p.first] = -((int)(abs(p.second) / 2)+1);
        }
        else
        {
            res[p.first] = -(int)(abs(p.second) / 2);
        }
        state = !state;
    }
    state = false;
    for (auto &p : pos)
    {
        if (state)
        {
            res[p.first] = (int)(p.second / 2) + 1;
        }
        else
        {
            res[p.first] = (int)(p.second / 2);
        }
        state = !state;
    }
    for (auto x : res)
        cout << x << "\n";

    return 0;
}
