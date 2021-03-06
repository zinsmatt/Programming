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

bool reflect(std::string& s) {
    for (auto c : s) {
        if (c == '3' || c == '4' || c == '6' || c == '7' || c == '9') return false;
    }
    string s2 = s;
    
    F (i, 5) {
        if (s[i] == '0') {
            s2[4-i] = '0';
        } else if (s[i] == '1') { 
            s2[4-i] = '1';
        } else if (s[i] == '2') {
            s2[4-i] = '5';
        } else if (s[i] == '5') {
            s2[4-i] = '2';
        } else if (s[i] == '8') {
            s2[4-i] = '8';
        }
    }
    s = s2;
    return true;
}

string stringify(int h, int m) {
    stringstream ss;
    ss << std::setw(2) << std::setfill('0') << h << ":" << std::setw(2) << std::setfill('0') << m;
    return ss.str();
}

std::pair<int, int> intify(const std::string& s) {
    return std::make_pair(std::stoi(s.substr(0, 2)), std::stoi(s.substr(3, 2)));
}

int main()
{
    int t = 1;
    cin >> t;
    F (ti, t) {
        int H, M;
        cin >> H >> M;
        std::string s;
        cin >> s;

        auto [h, m] = intify(s);

        while (1) {
            auto s = stringify(h, m);
            //std::cout << "s = " << s << "\n";
            auto s2 = s;
            if (reflect(s2)) {
                auto [hh, mm] = intify(s2);
                if (hh < H && mm < M) {
                    std::cout << s << "\n";
                    break;
                }
            }
            ++m;
            if (m == M) {
                m = 0;
                ++h;
            }
            if (h == H) {
                h = 0;
            }
        }
    }

    return 0;
}

