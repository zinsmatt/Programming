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





int solve(std::unordered_map<ll, ll>& m, int x)
{
    if (m.find(x) != m.end())
        return m[x];
    ll res;
    if (x % 2 == 0)
    {
        res = (x+1)*(x+1) - solve(m, x-1) - solve(m, x-2);
    }
    else
    {
        res = ((x+2)*(x+2))/2;
    }

    m[x] = res;
    return res;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll tt=1;
    cin >> tt;
    F(ttt, tt)
    {
        ll n, m;
        cin >> n >> m;
        vector<int> rows(n+1, -1);
        vector<int> cols(n+1, -1);
        F(i, m)
        {
            int r, c;
            cin >> r >> c;
            rows[r] = c;
            cols[c] = r;
        }

        ll res = 0;
        vector<bool> done(n+1, 0);
        for (int i = 1; i <=n;++i)
        {
            //std::cout << i << "\n";
            if (rows[i] == i) {
                done[i] = 1;
                continue;
            }
            if (rows[i] != -1)
            {
                if (cols[i] == -1)
                {
                    res++;

                    cols[rows[i]] = -1;
                    rows[i] = i;
                    cols[i] = i;
                }
                else
                {
                    int x = i;
                    int xx = cols[x];
                    //std::cout << "dep on " << xx << " ";

                    int nb = 1;
                    done[x] = 1;
                    std::vector<int> q = {i};
                    while (xx != -1 && !done[xx])
                    {
                        done[xx] = 1;
                        q.push_back(xx);
                        xx = cols[xx];
                        //std::cout << "dep on " << xx << " ";
                        ++nb;
                        //std::cout << "x xx = " << x << " " <<xx << "\n";
                    }
                    
                    //std::cout << "x = " << x << std::endl;
                    //std::cout << "xx = " << xx << std::endl;
                    //cout << " ";
                    if (xx == -1){
                        res += nb;
                      //  cout << " + "<< nb << "\n";
                    }
                    else{
                        res += nb + 1;
                        //cout << " + "<< nb << " + 1\n";
                    }
                    for (auto j : q)
                    {
                        cols[rows[j]] = -1;
                        cols[j] = j;
                        rows[j] = j;

                    }
                    //for (auto x : cols) cout << x << " ";
                    //cout << "\n";
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}
