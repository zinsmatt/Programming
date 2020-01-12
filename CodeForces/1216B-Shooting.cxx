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
    vector<ll> a(n);
    F(j, n)
    {
        cin >> a[j];
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&a](int i, int j) { return a[i] > a[j]; });
    ll cost = 0;
    for (int i = 0; i < n; ++i)
    {
    	cost += a[idx[i]] * i;
    }
    cost += n;
    cout << cost << "\n";
    for (auto id : idx)
    	cout << id + 1 << " ";
    cout << "\n";
    
    return 0;
}