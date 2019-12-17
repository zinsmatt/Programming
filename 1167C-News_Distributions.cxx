#include <iostream>
#include <bits/stdc++.h>
 
#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 
 
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> groups(m, vector<int>());
    vector<vector<int>> links(n, vector<int>());
    F(i, m)
    {
        int k;
        cin >> k;
        groups[i].resize(k);
        F(j, k)
        {
            int x;
            cin >> x;
            groups[i][j] = x-1;
            links[x-1].push_back(i);
        }
    }
    vector<int> res(n, 0);
    vector<int> pt(n, -1);
    vector<int> done(m, 0);
    int a = 0;


    F(i, n)
    {
        if (pt[i] != -1)
            continue;
        int count = 0;

        queue<int> qg;
        for(auto g : links[i])
            qg.push(g);

        while (qg.size() > 0)
        {
            auto g = qg.front();
            qg.pop();

            for (auto x: groups[g])
            {
                if (pt[x] == -1)
                {
                    ++count;
                    for (auto gg : links[x])
                    {
                        if (done[gg] == 0)
                            qg.push(gg);
                        done[gg] = 1;
                    }
                }
                pt[x] = a;
            }
        }
        
        res[a] = max(1, count);
        pt[i] = a;
        ++a;
    }

    F(i, n)
        cout << res[pt[i]] << " ";
    cout << std::endl;
    return 0;
}
