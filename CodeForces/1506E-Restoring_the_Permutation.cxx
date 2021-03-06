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
    // srand(time(0));
    // srand(1994);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	ll tt=1;
	cin >> tt;
	F(t, tt)
	{
        int n;
        cin >> n;
        vector<int> a(n);
        F (i, n) cin >> a[i];

        int i = 0;
        vector<int> max(n, 0), min(n, 0);
        vector<bool> done(n+1, false);
        std::priority_queue<int> pq;
        int X = 1;

        min[0] = a[0];
        max[0] = a[0];
        done[a[0]] = true;

        for (int x = 1; x < a[0]; ++x)
            pq.push(x);

        for (int i = 1; i < n; ++i)
        {
            if (a[i-1] < a[i])
            {
                min[i] = a[i];
                max[i] = a[i];
                done[a[i]] = true;

                for (int k = a[i-1]+1; k < a[i]; ++k)
                    pq.push(k);
            } else {
                while (done[X]) {
                    ++X;
                }
                min[i] = X;
                done[X] = true;
                max[i] = pq.top();
                pq.pop();
            }
        }


        for (auto x : min) std::cout << x << " ";
        std::cout << "\n";
        for (auto x : max) std::cout << x << " ";
        std::cout << "\n";


    }

    return 0;
}