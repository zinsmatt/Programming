// This is just a template solution used as initial script


#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>     /* abs */

 
#define F(i, n) for (ll i = 0; i < n; ++i)

#define VPRINT(name, v) \
    cout << name << " : "; \
    for (const auto& e : v) { \
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


int find(std::vector<int>& sets, int x) {
    if (sets[x] == -1) return x;
    else {
        auto ret = find(sets, sets[x]);
        sets[x] = ret;
        return ret;
    }
}

void union_(std::vector<int>& sets, int x, int y) {
    auto root_x = find(sets, x);
    auto root_y = find(sets, y);
    if (root_x != root_y) {
        sets[root_y] = root_x;
    }
}

bool suffi(vector<ll>& need, vector<ll>& prov)
{
    F (i, need.size())
    {
        if (need[i]>prov[i])
        return false;
    }
    return true;
}

vector<ll> add(vector<ll>& a, vector<ll>& b)
{
    vector<ll> res = a;
    F (i, a.size())
    res[i] += b[i];
    return res;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	ll tt=1;
	cin >> tt;
	F(t, tt)
	{
        ll n, k;
        cin >> n >> k;
        vector<ll> p(n);
        F (i, n) cin >> p[i];
        p.push_back(1);
        p.push_back(k);

        sort(p.begin(), p.end());
        
        ll max_a = 0;
        for (int i = 0; i < p.size()-1; ++i)
        {
            for (int j = 0; j < p.size()-1; ++j)
            {
                ll a = 0;
                if (i == j)
                {
                    if (i == 0)
                    {
                        a += p[1]-1;
                    }
                    else if (i == p.size()-2)
                    {
                        a += k-p[i];
                    } else {
                        a += p[i+1]-p[i]-1;
                    }
                }
                else
                {
                    if (i == 0)
                    {
                        a += p[1]-1;
                    }
                    else if (i == p.size()-2)
                    {
                        a += k-p[i];
                    } else {
                        a += (p[i+1]-p[i])/2;
                    }

                    if (j == 0)
                    {
                        a += p[1]-1;
                    }
                    else if (j == p.size()-2)
                    {
                        a += k-p[j];
                    } else {
                        a += (p[j+1]-p[j])/2;
                    }
                }
                max_a = std::max(max_a, a);
            }
        }

        double da = max_a;
        cout.precision(8);
        cout << "Case #" << t+1 << ": " << std::fixed << da / k << "\n";

    }
    return 0;
}
