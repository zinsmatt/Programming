#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#define F(i, n) for (int i = 0; i < n; ++i)
using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 


int main()
{
    int t;
    cin >> t;
    F(tt, t)
    {
        ll n, p, k;
        cin >> n >> p >> k;
        vector<int> a(n);
        int imp = 0, pair = 0;
        F(i, n)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        std::vector<ll> cost(1+n, -1);
        cost[0] = 0;

        for (int i = 1; i <= n; ++i)
        {
            ll prev = cost[i-1];
            if (i >= k)
            {
                if (prev == -1 || prev > cost[i-k])
                    prev = cost[i-k];
            }
            ll nouv = a[i-1] + prev;
            if (prev >=0 && nouv <= p)
            {
                cost[i] = nouv;
            }
        }
        //for( auto c : cost)
        //    cout << c << " " ;
        //cout << "\n";
        int i = cost.size()-1;
        while (i >= 0 && cost[i] == -1)
            --i;
        cout << i << "\n";


    }
    return 0;
}