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



int main()
{
	ll n;
	cin >> n;
	vector<ll> a(n);

	F(i, n)
	{
		cin >> a[i];
	}

	vector<int> idx(n);
	iota(idx.begin(), idx.end(), 0);
	sort(idx.begin(), idx.end(), [&a](int i, int j) {
		auto d1 = i - a[i];
		auto d2 = j - a[j];
		if (d1 == d2)
			return i < j;
		else
			return d1 < d2;
	});

	vector<int> mapping(n, 0);
	F(i, n)
	{
		mapping[idx[i]] = i;
	}

	//VPRINT("idx = ", idx)
	//VPRINT("mapping = ", mapping)
	vector<ll> accu(n, 0);
	vector<ll> add(n, 0);
	F(i, n)
	{
		accu[i] = a[i];
		int j = mapping[i];
		int d = idx[j] - a[idx[j]];
		--j;

		if (j >= 0 && d == idx[j] - a[idx[j]])
		{

			//if (i-j > 0 && i-j == a[i]-a[j])
			//cout << "cmp  accu of " << i << " + accu of " << idx[j];
			//cout << " would give " << a[i]+accu[idx[j]] << "\n";
			accu[i] = max(accu[i], a[i]+add[j]);
		}

		add[j+1] = accu[i];
	}
	//VPRINT("accu ", accu)
	cout << *max_element(accu.begin(), accu.end()) << std::endl;
    return 0;
}