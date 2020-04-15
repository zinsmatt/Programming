// This is just a template solution used as initial script
#include <bits/stdc++.h> 
#include <stdlib.h>     /* abs */
#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <map>

using namespace std;

using ll = long long;
using ull = unsigned long long;

#define INF std::numeric_limits<int>::max()
#define LLINF std::numeric_limits<long long>::max()

#define F(i, n) for (ll i = 0; i < n; ++i)
 
#define VPRINT(name, v) \
    cout << name << " : "; \
    for (auto& e : v) { \
        cout << e << " "; \
    } \
    cout << std::endl;
 
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

void primeFactors(vector<int>& v, int n)
{
    while (n % 2 == 0) {v.push_back(2);n = n/2;}
    for (int i = 3; i <= sqrt(n); i = i + 2) {while (n % i == 0){ v.push_back(i); n = n/i;}}
    if (n > 2) v.push_back(n);
}

vector<int> fct(int a, int b)
{
    int it = 0;
    while(b < a)
    {
        b += pow(2, it);
        it++;
    }
    return {b, it};
}


int count(const unordered_map<string, int>& m, const string& k)
{
	if (m.find(k) == m.end()) return 0;
	return m.at(k);
}

vector<int> diff(const vector<int>& c1, const vector<int>& c2)
{
	vector<int> res = c1;
	F(i, c1.size())
	res[i] -= c2[i];
	return res;
}


int max_min(const vector<int>& a, const vector<int>& b)
{
	int res = 0;
	F(i, a.size())
	{
		res = max(res, min(a[i], b[i]));
	}
	return res;
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	ll t;
	cin >> t;
	F(i, t)
	{
		ll n;
		cin >> n;
		vector<int> a(n);

		vector<vector<int>> counts(n, vector<int>(26, 0));
		F(i, n) {
			cin >> a[i]; a[i]--;
			if (i > 0)
				counts[i] = counts[i-1];
			counts[i][a[i]]++;
		}

		int res = 0;
		F(i, n)
		{
			for (int j = i +1; j < n; ++j)
			{

				const auto&  left = counts[i];
				vector<int> right = diff(counts.back(), counts[j-1]);

				vector<int> mid = diff(counts[j-1], counts[i]);


				int max_mid = *std::max_element(mid.begin(), mid.end());
				int max_out = max_min(left, right);
				res = max(res, max_out*2+max_mid);
			}
		}

		cout << max(1, res) << "\n";

	
	}


    return 0;
}
