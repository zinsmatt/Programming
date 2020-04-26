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

ll f(vector<int>& v)
{
	int a = 0;
	ll res = 0;
	while (a < v.size() && v[a] != 2)
	{
		res += pow(2, a) * v[a];
		++a;
	}
	return res;
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll tt=1;
    cin >> tt;
    F(tti, tt)
	{
		ll x, y;
		cin >> x >> y;

		string xpos="", xneg="", ypos="", yneg="";
		if (x > 0)
		{
			xpos='E';
			xneg='W';
		} else if (x < 0)
		{
			xpos='W';
			xneg='E';
		}

		if (y > 0)
		{
			ypos='N';
			yneg='S';
		} else if (y < 0)
		{
			ypos='S';
			yneg='N';
		}

		x = abs(x);
		y = abs(y);

		if ( abs(x) %2 == abs(y)%2)
		{
			cout << "Case #" << tti+1 << ": ";
			cout << "IMPOSSIBLE\n";
			continue;
		}

		auto a = binary2(x);
		auto b = binary2(y);
		a.resize(50, 2);
		b.resize(50, 2);
		//VPRINT("a", a)
		//VPRINT("b", b)

		int i=1;
		bool ok = true;
		stringstream ss;
		while (a[i] != 2 || b[i] != 2)
		{
			if ((a[i] == 0 || a[i] == 2) && (b[i] == 0 || b[i] == 2))
			{
				if (a[i-1] == 1)
				{
					a[i] = 1;
					a[i-1] = -1;
				}
				else if (a[i-1] == -1)
				{
					a[i] = -1;
					a[i-1] = 1;
				}
				else if (b[i-1] == 1)
				{
					b[i] = 1;
					b[i-1] = -1;
				}
				else if (b[i-1] == -1)
				{
					b[i] = -1;
					b[i-1] = 1;
				}
			}
			else if(a[i] == 1 && b[i] == 1)
			{
				if (a[i-1] == -1 || b[i-1] == -1)
				{
					if (a[i-1] == -1)
					{
						a[i] = 0;
						a[i-1] = 1;
					}
					else{
						b[i] = 0;
						b[i-1] = 1;
					}
				}
				else if (a[i-1] == 1)
				{
					int j = i+1;
					while (a[j] == 1)
					{
						a[j] = 0;
						++j;
					}
					a[j] = 1;
					a[i] = 0;
					a[i-1] = -1;
				}
				else if (b[i-1] == 1)
				{
					int j = i+1;
					while (b[j] == 1)
					{
						b[j] = 0;
						++j;
					}
					b[j] = 1;
					b[i] = 0;
					b[i-1] = -1;
				}
			}
			++i;
		}
		//VPRINT("a", a)
		//VPRINT("b", b)
		cout << "Case #" << tti+1 << ": ";
		if (ok)
		{
			//cout << f(a) << "\n";
			//cout << f(b) << "\n";

			int i = 0;
			while (i < 50)
			{
				if (a[i] == 1)
					ss << xpos;
				else if (a[i] == -1)
					ss << xneg;
				else if (b[i] == 1)
					ss << ypos;
				else if (b[i]== -1)
					ss << yneg;
				++i;
			}
			cout << ss.str() << "\n";
		}
		else
		{
			cout << "IMPOSSIBLE\n";
		}



    }

    return 0;
}

