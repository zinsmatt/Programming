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

int check(std::vector<int> arr){
    auto n = arr.size();
    ll total_cost = 0;
    F (i, n-1) {
        auto mini = std::min_element(arr.begin()+i, arr.end());
        auto cost = std::distance(arr.begin()+i, mini+1);
        total_cost += cost;
        std::reverse(arr.begin()+i, mini+1);
    }
    //std::cout << "Check cost = " << total_cost << std::endl;
    return total_cost;
}


int main()
{
	ll tt=1;
	cin >> tt;
	F(t, tt)
	{
        int N, C;
        cin >> N >> C;
        
        std::vector<int> a(N);
        std::iota(a.begin(), a.end(), 1);

        if (C < N-1 || C > N*(N+1)/2-1) {
            std::cout << "Case #" << t+1 << ": " << "IMPOSSIBLE\n";
        }
        else {

            int l = 0, r = N-1;
            C -= (N-1);
            int size = N-1;
            int x = 0;
            F (i, N-1) {
                int d = std::min(C, size);
                //std::cout << "x = " << x << "\n";
                //std::cout << "d = " << d << "\n";

                if (i % 2 == 0) {
                    reverse(a.begin()+x, a.begin()+x+d+1);
                    x += d-1;
                } else {
                    reverse(a.begin()+x-d, a.begin()+x+1);
                    x -= d-1;
                }
                C -= d;
                --size;
                //VPRINT("a", a);
                //std::cout << "reste C = " << C << "  size = " << size << std::endl;
            }

            //VPRINT("final a", a)

            std::cout << "Case #" << t+1 << ": ";
            for (auto x : a)
                std::cout << x << " ";
            std::cout << "\n";

        }
    }

    return 0;
}
