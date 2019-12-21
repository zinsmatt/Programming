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
    vector<ll> a(n), b(n);
    unordered_map<ll, ll> mapa;
    F(i, n)
    {
        cin >> a[i];
        if (mapa.find(a[i]) != mapa.end())
            mapa[a[i]]++;
        else
            mapa[a[i]] = 1;
    }
    vector<ll> aa, occa;
    for (auto& p : mapa)
    {
        aa.push_back(p.first);
        occa.push_back(p.second);
    }
    vector<ll> idx(aa.size());
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&aa](ll x, ll y){return aa[x] < aa[y];});
    vector<ll> occas = occa;
    for (int i = 0; i < occa.size(); ++i)
    {
        occas[i] = occa[idx[i]];
    }
    occa = occas;
    sort(aa.begin(), aa.end());

    unordered_map<ll, ll> mapb;
    F(i, n)
    {
        cin >> b[i];
        if (mapb.find(b[i]) != mapb.end())
            mapb[b[i]]++;
        else
            mapb[b[i]] = 1;
    }
    vector<ll> bb, occb;
    for (auto& p : mapb)
    {
        bb.push_back(p.first);
        occb.push_back(p.second);
    }
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&bb](ll x, ll y){return bb[x] < bb[y];});
    vector<ll> occbs = occb;
    for (int i = 0; i < occb.size(); ++i)
    {
        occbs[i] = occb[idx[i]];
    }
    occb = occbs;
    sort(bb.begin(), bb.end());

    const int M = aa.size();
    ll res = 1e10;
    for (int d = 0; d < M; ++d)
    {
        ll dref = bb[d] - aa[0];
        if (dref < 0)
            dref += m;
        bool ok = true;
        for (int i = 0; i < M; ++i)
        {
            if (occa[i] != occb[(i+d)%M] ||
                (aa[i] + dref) % m != bb[(i+d)%M])
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            res = min(res, dref);
        }
    }
    cout << res;

   
    return 0;
}