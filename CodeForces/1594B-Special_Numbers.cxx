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

bool suffi(vector<ll>& need, vector<ll>& prov)
{
    F (i, need.size())
    {
        if (need[i]>prov[i])
        return false;
    }
    return true;
}

vector<ll> add(vector<ll>& a, vector<ll>& b)
{
    vector<ll> res = a;
    F (i, a.size())
    res[i] += b[i];
    return res;
}

bool roar(ll x)
{
    auto s = std::to_string(x);
    for (int d = 1; d <= s.size()/2; ++d)
    {
        auto b = stoll(s.substr(0, d));
        stringstream ss;
        while (ss.str().size() < s.size())
        {
            ss << b;
            ++b;
        }
        if (s == ss.str())
            return true;
    }
    return false;
}


string fnot(std::string s)
{
    int first = -1;
    F (i, s.size())
    {
        if (s[i] == '1')
            s[i] = '0';
        else
        {
            s[i] = '1';
            if (first == -1) first = i;
        }
    }
    if (first == -1) return "0";
    else return s.substr(first);
}

int count_var(const std::string& s)
{
    int var = 0;
    F(i, s.size()-1)
    {
        if (s[i] != s[i+1])
         var++;
    }
    return var;
}

int modpow(ll x, ll y, ll p)
{
    // x^y mod p
    int res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	ll tt=1;
	cin >> tt;
	F(t, tt)
    {
        const ll P = 1000000007;
        ll n, k;
        cin >> n >> k;
        ll res = 0;
        int i = 0;
        while (k)
        {
            auto r = k % 2;
            if (r)
                res += modpow(n, i, P);
            res %= P;
            k /= 2;
            ++i;
        }
        cout << res << "\n";       

    }
    return 0;
}