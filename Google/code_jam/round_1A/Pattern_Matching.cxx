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
 
void primeFactors(vector<int>& v, int n)
{
    while (n % 2 == 0) {v.push_back(2);n = n/2;}
    for (int i = 3; i <= sqrt(n); i = i + 2) {while (n % i == 0){ v.push_back(i); n = n/i;}}
    if (n > 2) v.push_back(n);
}

vector<string> split(const string& s)
{
	vector<string> res;
	int prev = 0;
	F(i, s.size())
	{
		if (s[i] == '*')
		{
			res.push_back(s.substr(prev, i-prev));
			prev = i+1;
		}
	}
	if (prev < s.size())
		res.push_back(s.substr(prev));
	else
		res.push_back("");
	return res;
}

bool is_substr(const string& a, const string &b, bool front)
{
	if (b.size() == 0)
		return true;
	if (front)
	{
		int i = 0;
		while (i < b.size())
		{
			if (a[i] != b[i])
				return false;
			++i;
		}
		return true;
	}
	else
	{
		int i = 0;
		while (i < b.size())
		{
			if (a[a.size()-1-i] != b[b.size()-1-i])
				return false;
			++i;
		}
		return true;
	}
}


int main()
{
	
//	std::ios::sync_with_stdio(false);
  //  std::cin.tie(nullptr);

	ll tt=1;
	cin >> tt;
	F(tti, tt)
	{ 
		ll n;
		cin >> n;
		vector<string> s(n);
		vector<vector<string>> splits;

		int max_splits = 0;

		F(i, n) {

			cin >> s[i];
			splits.push_back(split(s[i]));
			//VPRINT("splits i ", splits.back());
			//cout << splits.back().size() << "\n";
			max_splits = max(max_splits, (int) splits.back().size());

		}

		string res = "";
		bool good = true;
		//cout << "max splits " << max_splits << "\n";
		F(i, max_splits)
		{
			int largest = 0, largest_j = -1;
			F(j, n)
			{
				if (splits[j][i].size() > largest)
				{
					largest = splits[j][i].size();
					largest_j = j;
				}
			}
			if (largest_j == -1)
			{
				continue;
			}
			//cout << "largest lj " << largest << " " << largest_j << std::endl;
			res += splits[largest_j][i];
			//cout << "res = " << res << "\n";
			auto const& ref = splits[largest_j][i];
			//cout << "ref = " << ref << "\n";

			bool ok = true;
			F(j, n)
			{
				if (j != largest_j)
				{
					if (!is_substr(ref, splits[j][i], i == 0))
					{
						ok = false;
						break;
					}
				}
			}
			if (!ok)
			{
				good = false;
				break;
			}
		}

		cout << "Case #" << tti+1 << ": ";

		if (good)
		{
			cout << res << "\n";
		}
		else
		{
			cout << "*\n";
		}






	}

    return 0;
}
