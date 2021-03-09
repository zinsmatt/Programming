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



int main()
{
	ll tt=1;
	cin >> tt;
	F(t, tt)
	{
        int n;
        cin >> n;
        std::vector<ull> arr(n);
        F (i, n) cin >> arr[i];

        std::vector<int> indices(n);
        std::iota(indices.begin(), indices.end(), 1);
        sort(indices.begin(), indices.end(), [&arr](int a, int b) {
            return arr[a-1] < arr[b-1];
        });
        sort(arr.begin(), arr.end());


        std::vector<ull> cumul(n, 0);
        vector<bool> good(n, true);
        cumul[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            if (arr[i] > cumul[i-1]) {
                good[i-1] = false;
            }
            cumul[i] = cumul[i-1] + arr[i];
        }

        /*VPRINT("CUMUL", cumul);
        VPRINT("good", good);
        VPRINT("indices", indices)*/

        vector<int> res;
        int i = n-1;
        while (i >= 0 && good[i]) {
            res.push_back(indices[i]);
            --i;
        }
        std::sort(res.begin(), res.end());
        std::cout << res.size() << "\n";
        for (auto x : res)
            cout << x << " ";
        std::cout << "\n";
	}
    

    return 0;
}