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

double distance(const std::vector<double>& pt0, const std::vector<double>& pt1)
{
    return std::sqrt(std::pow(pt0[0]-pt1[0], 2) + std::pow(pt0[1]-pt1[1], 2));
}

#define TO_INT(c) static_cast<ll>(c-'A'+1)
#define P 253
#define M 1000000009

int main()
{
	ll tt=1;
	cin >> tt;
	F(t, tt)
	{
        std::string s;
        cin >> s;

        bool res = false;
        for (int ps = 1; ps <= s.size(); ++ps) {
            bool bad = false;
            char prev = '0';
            for (int i = 0; i < ps; ++i) {
                if (s[i] == '1' && prev == '1') {
                    bad = true;
                }
                prev = s[i];
            }

            prev = '1';
            for (int j = ps; j < s.size(); ++j) {
                if (s[j] == '0' && prev == '0') {
                    bad = true;
                }
                prev = s[j];
            }

            if (!bad) {
                res = true;
                break;
            }
        }

        if (res)
            std::cout << "YES\n";
        else 
            std::cout << "NO\n";
       
	}

    return 0;
}