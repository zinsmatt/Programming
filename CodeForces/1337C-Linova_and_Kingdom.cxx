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
    cout << std::endl;

#define LPRINT(name, l) \
    cout << "list " << name << " : "; \
    for (auto it = l.begin(); it != l.end(); ++it) { \
        cout << *it << " "; \
    } \
    cout << std::endl;

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

vector<int> binary2(ll x)
{
	vector<int> res;
	while (x > 0)
	{
		res.push_back(x % 2);
		x >>= 1;
	}
	return res;
}


int f(vector<vector<int>>& edges, int x, vector<int>& dists, vector<int>& derr, int d, vector<bool>& done)
{
	dists[x] = d;
	done[x] = true;

	int count = 0;
	for (auto e : edges[x])
	{
		if (!done[e])
		{
			auto r = f(edges, e, dists, derr, d+1, done);
			count += r;
		}
	}
	derr[x] = count;
	return count+1;
}


using namespace std::chrono;
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);



	ll tt = 1;
//	cin >> tt;
	F(tti, tt)
	{

		ll n, k;
		cin >> n >> k;
		vector<vector<int>> edges(n, vector<int>());
		vector<int> order(n, 0);
		vector<int> leaves;
		F(i, n-1)
		{
			int a, b;
			cin >> a >> b;
			--a;--b;
			edges[a].push_back(b);
			edges[b].push_back(a);
			order[a]++;
			order[b]++;
		}
		vector<int> dists(n, 0);
		vector<int> derr(n, 0);

		vector<bool> done(n, false);


		f(edges, 0, dists, derr, 0, done);


/*

		F(i, n)
		{
			if (i != 0 && order[i] == 1)
				leaves.push_back(i);
		}



		{

			queue<int> q;
			q.push(0);
			queue<int> d;
			d.push(0);

			ll res = 0;
			vector<bool> done(n, false);
			while (q.size() > 0)
			{
				int x = q.front();
				q.pop();
				int dist = d.front();
				d.pop();
				done[x] = true;
				dists[x] = dist;

				for (auto e : edges[x])
				{
					if (!done[e])
					{
						q.push(e);
						d.push(dist+1);
					}
				}
			}
		}


		for (auto l : leaves)
		{

			queue<int> q;
			q.push(l);
			queue<int> d;
			d.push(0);

			ll res = 0;
			while (q.size() > 0)
			{
				int x = q.front();
				q.pop();
				int dist = d.front();
				d.pop();

				bool first = false;
				if (derr[x] == 0)
					first = true;

				derr[x] += dist;

				for (auto e : edges[x])
				{
					if (dists[e] < dists[x])
					{
						q.push(e);
						if (first)
							d.push(dist+1);
						else
							d.push(dist);
					}
				}
			}
		}*/

		vector<int> score(n, 0);
		F(i, n)
		{
			score[i] = dists[i]-derr[i];
		}


		//VPRINT("dists ", dists)
		//VPRINT("derr ", derr)
		order[0] = INF;

		sort(score.begin(), score.end(), std::greater<int>());
		/*vector<int> idx(n);
		iota(idx.begin(), idx.end(), 0);
		sort(idx.begin(), idx.end(), [&score](int a, int b) {
			return score[a] > score[b];
		});*/
		//VPRINT("score ", score)


		ll res = std::accumulate(score.begin(), score.begin()+k, 0ll);
/*
		vector<bool> tourist(n, true);

		F(j, k)
		{
			tourist[idx[j]] = false;
		}

		queue<int> q;
		q.push(0);
		queue<int> d;
		d.push(0);

		ll res = 0;
		vector<bool> done(n, false);
		while (q.size() > 0)
		{
			int x = q.front();
			q.pop();
			int dist = d.front();
			d.pop();
			done[x] = true;

			if (tourist[x] == false)
			{
				res += dist;
			}

			dist += tourist[x];

			for (auto e : edges[x])
			{
				if (!done[e])
				{
					q.push(e);
					d.push(dist);
				}
			}
		}*/
		cout << max(0ll, res) << "\n";


	}

    return 0;
}
