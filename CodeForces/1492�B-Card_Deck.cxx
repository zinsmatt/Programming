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
    int t = 1;
    cin >> t;
    F (ti, t) {
        int n;
        cin >> n;
        std::vector<int> arr(n);
        std::vector<int> p(n+1, 0);
        F (i, n) {
            cin >> arr[i];
            p[arr[i]] = i;
        }

        int i = n;
        while (i > 0) {
            int j = p[i];
            while (j < n && arr[j] != -1) {
                cout << arr[j] << " ";
                arr[j] = -1;
                ++j;

            }

            --i;
        }
        std::cout << "\n";
    }

    return 0;
}

