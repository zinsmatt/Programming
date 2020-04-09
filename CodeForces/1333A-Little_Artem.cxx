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



int main()
{

	ll tt;
	cin >> tt;
	F(tti, tt)
	{ 
		int h, w;
		cin >> h >> w;
		if (h == 1)
		{
			F(j, w)
			{
				if (j % 2 == 0)
					cout << "B";
				else
					cout << "W";
			}
		}
		else if (w == 1)
			{
				F(i, h)
				{
					if (i % 2 == 0)
						cout << "B\n";
					else
						cout << "W\n";
				}
			}
		else
		{


			F(i, h-1)
			{
				F(j, w)
				{
					if (j % 2 == i % 2)
						cout << "B";
					else{
						cout << "W";	
					} 
				}
				cout << "\n";
			}

			if (h % 2 == 0)
			{
				{
					cout << "B";
					F(j, w-1)
					{
						if (j%2==0)
							cout << "B";
						else cout << "W";
					}
				}
				cout << "\n";
			}
			else
			{
				if (w % 2 == 1)
				{
					F(j, w)
					{
						if (j%2==0)
							cout << "B";
						else cout << "W";
					}
				}
				else
				{
					F(j, w-1)
					{
						if (j%2==0)
							cout << "B";
						else cout << "W";
					}
					cout << "B";
				}
				cout << "\n";
			}
		}

	}

    return 0;
}
