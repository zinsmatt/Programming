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

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

	ll t;
	cin >> t;
	F(i, t)
	{

		F(i, 9)
		{
			string s;
			cin >> s;
			int iblock = i%3;
			int icol = i/3;
			int idx = iblock * 3 + icol;


			int val = s[idx]-'0';
			val--;
			val = (val+1)%9;
			val++;
			s[idx] = (char)('0'+val);
			cout << s<<"\n";
		}
	}


    return 0;
}
