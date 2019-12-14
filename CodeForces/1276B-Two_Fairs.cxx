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
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        vector<vector<int>> edges(n, vector<int>());
        F(i, m)
        {
            int u, v;
            cin >> u >> v;
            edges[u-1].push_back(v-1);
            edges[v-1].push_back(u-1);
        }
        vector<int> done(n, 0);
        queue<int> q;
        q.push(a-1);
        while (q.size() > 0)
        {
            int cur = q.front();
            q.pop();
            if (cur == b-1 || done[cur] == 1)
            {
                continue;
            }
            else
            {
                done[cur] = 1;
                for (auto e : edges[cur])
                {
                    q.push(e);
                }
            }
        }

        vector<int> done2(n, 0);
        queue<int> q2;
        q2.push(b-1);
        while (q2.size() > 0)
        {
            int cur = q2.front();
            q2.pop();
            if (cur == a-1 || done2[cur] == 1)
            {
                continue;
            }
            else
            {
                done2[cur] = 1;
                for (auto e : edges[cur])
                {
                    q2.push(e);
                }
            }
        }

        ll l = 0, r = 0;
        for (int i = 0; i < n; ++i)
        {
            if (done[i] == 0 && done2[i] == 1)
            {
                ++r;
            }
            else if (done[i] == 1 && done2[i] == 0)
            {
                ++l;
            }
        }
        r = max(0ll, r-1);
        l = max(0ll, l-1);
        cout << l * r << std::endl;

    }
    
    
    
    return 0;
}