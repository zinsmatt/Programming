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

std::vector<int> A(26, 0);
char diff(const std::string& s)
{
    fill(A.begin(), A.end(), 0);
    for (auto c : s)
    {
        A[c-'a']=1;
    }
    int i = 0;
    while (i < 26 && A[i])
        ++i;
    return (char)(i+'a');

}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll tt=1;
    cin >> tt;
    F(ttt, tt)
    {
        std::string s;
        cin >> s;
        ll res = 0;
        if (s.size() == 1)
        {
            cout << "0\n";
        }
        else if (s.size() == 2)
        {
            cout << (int)(s[0] == s[1]) << "\n";
        }
        else
        {
            for (int i = 1; i < s.size(); ++i)
            {

                int l = std::max(0, i-2);
                int r = std::min((int)s.size()-1, i+2);
                int to = 0;
                if (i > 1)
                {
                    if (s[i] == s[i-1] || s[i] == s[i-2])
                        to = 1;
                } else 
                {
                    if (s[i] == s[i-1])
                        to=1;
                }

                if (to)
                {
                    s[i] =  diff(s.substr(l, r-l+1));
                    ++res;
                }
            }
            cout << res << "\n";
        }

    }
    return 0;
}
