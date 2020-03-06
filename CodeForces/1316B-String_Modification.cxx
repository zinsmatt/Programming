// This is just a template solution used as initial script


#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>     /* abs */

 
#define F(i, n) for (ll i = 0; i < n; ++i)

#define VPRINT(name, v) \
    cout << name << " : "; \
    for (auto& e : v) { \
        cout << e << " "; \
    } \
    cout << std::endl; \

#define LPRINT(name, l) \
    cout << "list " << name << " : "; \
    for (auto it = l.begin(); it != l.end(); ++it) { \
        cout << *it << " "; \
    } \
    cout << std::endl; \

using ll =  long long;
using ull = unsigned long long;
 
using namespace std;
 
#define INF std::numeric_limits<int>::max()
#define LLINF std::numeric_limits<long long>::max()


template <typename T, typename A>
int arg_max(std::vector<T, A> const& vec) {
  return static_cast<int>(std::distance(vec.begin(), max_element(vec.begin(), vec.end())));
}

template <typename T, typename A>
int arg_min(std::vector<T, A> const& vec) {
  return static_cast<int>(std::distance(vec.begin(), min_element(vec.begin(), vec.end())));
}

int dfs(const vector<vector<int>>& g, vector<int>& dist, int start, int end=-1)
{
    // g is a list of neighbours for each node
    // dist is assumed to be filled with INF
    queue<int> q;
    q.push(start);
    queue<int> d;
    d.push(0);
    while (q.size() > 0)
    {
        auto x = q.front();
        auto dd = d.front();
        q.pop();
        d.pop();

        if (dist[x] == INF)
        {
            dist[x] = dd;
            if (end == x)
                break;

            for (auto e: g[x]) {
                q.push(e);
                d.push(dd+1);
            }
        }
    }
    if (end >= 0 && end < dist.size())
        return dist[end];
    else
        return -1;
}

std::string rotate(const std::string& s, int i)
{
    //cout << "!!! " << s.size() << std::endl;
    if (i  == 0)
    {
        return s;
    }
    else if (i == s.size()-1)
    {
        string res = s;
        reverse(res.begin(), res.end());
        return res;
    }
    else
    {
        //cout << " rotate i = " << i << "\n";
        string res = s;
        auto tmp = res.substr(i);
        auto rest = res.substr(0, i);
        if ((i+1) % 2 == s.size() % 2)
        {
            reverse(rest.begin(), rest.end());
        }
        auto resu = tmp + rest;
        
        return resu;
    }
}

char buffer[5001];

int main()
{
    buffer[5000] = '\0';

    ll tt;
    cin >> tt;
    F(t, tt)
    {
        ll n;
        cin >> n;
        scanf("%s", &buffer[0]);
        string s(buffer, n);
        vector<string> possibles;
        vector<int> possibles_k;
        auto min = *std::min_element(s.begin(), s.end());
        F(i, n)
        {
            if (s[i] == min)
            {
                possibles.emplace_back(rotate(s, i));
                possibles_k.push_back(i);
            }
        }
        

        vector<int> ind(possibles.size());
        iota(ind.begin(), ind.end(), 0);
        sort(ind.begin(), ind.end(), [&possibles, &possibles_k](int i, int j) {
            if (possibles[i] == possibles[j])
                return possibles_k[i] < possibles_k[j];
            else
                return possibles[i] < possibles[j];
        });

       
        cout << possibles[ind.front()] << "\n";
        cout << possibles_k[ind.front()] + 1 << "\n";
    }
    


    return 0;
}