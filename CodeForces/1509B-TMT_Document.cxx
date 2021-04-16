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





int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	ll tt=1;
	cin >> tt;
	F(t, tt)
	{
        int n;
        cin >> n;
        std::string s;
        cin >> s;
        ll ct = 0, cm = 0;
        for (auto& c : s)
        {
            if (c== 'T') ct++;
            else cm++;
        }

        if (cm*2 != ct) {
            std::cout << "NO\n";
        } else
        {
            // ll acc_t = 0, dec_t = 0, acc_m = 0;
            // for (auto c : s) {
            //     if (c == 'T')
            //     {
            //         if (acc_t < cm)
            //         {
            //             acc_t++;
            //         }
            //         else {
            //             acc_t--;
            //         }
            //     } else {
            //         acc_m++;
            //     }
            // }
            // if (acc_m == cm && acc_t == 0) std::cout << "YES\n";
            // else std::cout << "NO\n";

            vector<ll> left(n, 0), right(n, 0);
            auto s_rev = s;
            reverse(s_rev.begin(), s_rev.end());
            if (s[0] == 'T') left[0] = 1;
            if (s_rev[0] == 'T') right[0] = 1;
            int m_left = 0, m_right = 0;
            bool ok = true;
            for (int i = 1; i <n; ++i)
            {
                left[i] = left[i-1] + (int)(s[i] == 'T');
                right[i] = right[i-1] + (int)(s_rev[i] == 'T');
            }
            for (int i = 0; i <n; ++i)
            {
                if (s[i] == 'M')
                {   
                    m_left++;
                    if (left[i] < m_left)
                    {
                        ok = false;
                        break;
                    }
                }
                if (s_rev[i] == 'M')
                {   
                    m_right++;
                    if (right[i] < m_right)
                    {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) std::cout << "YES\n";
            else cout << "NO\n";


        }


        
    }

    return 0;
}
