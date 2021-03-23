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

double distance(const std::vector<double>& pt0, const std::vector<double>& pt1)
{
    return std::sqrt(std::pow(pt0[0]-pt1[0], 2) + std::pow(pt0[1]-pt1[1], 2));
}

#define TO_INT(c) static_cast<ll>(c-'A'+1)
#define P 253
#define M 1000000009

int main()
{
    // std::ifstream input_file("/home/mzins/Downloads/swerc/uniqueactivities/data/secret/test12.in");
    std::ifstream input_file("/home/mzins/Downloads/swerc/uniqueactivities/data/secret/test_pattern01.in");
	ll tt=1;
	// cin >> tt;
	F(t, tt)
	{
        std::string s;
        cin >> s;
        //std::getline(input_file, s);
        int n = s.size();
        std::unordered_map<std::string, std::pair<int, int>> m;
        // F (i, n) {
        //     F (j, n-i+1) {
        //         auto sub = s.substr(i, j);
        //         if (m.find(sub) != m.end()) {
        //             m[sub].first++;
        //         } else {
        //             m[sub] = {1, i};
        //         }
        //     }
        // }
    
        int l = 1;
        int r = n;
        std::string res = s;
        while (l < r) {

            int d = (l+r)/2;

            bool ok = false;
            //std::cout << "d = " << d << std::endl;
            // calc hashes
            
            std::unordered_map<ll, std::pair<int, int>> mm;
            // build initial hash of size d
            ll h = 0;
            F (k, d) {
                h = (h * P) % M;
                h = (h + TO_INT(s[k])) % M;
            }
            //std::cout << "init hash = " << h << std::endl;
            mm[h] = {1, 0};

            // Maximal power of p
            ll power = 1;
            F (k, d-1) {
                power = (power * P) % M;
            }
            //std::cout << "power = " << power << std::endl;
            for (int j = 1; j < n-d+1; ++j) {
                h -= (TO_INT(s[j-1])*power) % M;
                // std::cout << "h minus " << h << "\n";
                if (h < 0) h+= M;
                h = (h * P) % M;
                // std::cout << "h power " << h << "\n";

                h = (h + TO_INT(s[j+d-1])) % M;
                // std::cout << "h plus " << h << "\n";


              //  std::cout << h << std::endl;
                if (mm.find(h) != mm.end()) {
                    mm[h].first++;
                } else {
                    mm[h] = {1, j};
                }
            }

            int best_index = n+1;
            for (auto p : mm) {
                if (p.second.first == 1 && p.second.second < best_index) {
                    best_index = p.second.second;
                }
            }
            if (best_index < n) {
                res = s.substr(best_index, d);
                ok = true;
            }


            if (ok) {
                r = d;
            } else {
                l = d+1;
            }
        }


        // std::string res = s;
        // int best_index = n+1;
        // for (auto& p : m) {
        //     if (p.second.first == 1 && (p.first.size() < res.size() 
        //         || p.first.size() == res.size() && p.second.second < best_index)) {
        //         best_index = p.second.second;
        //         res = p.first;                
        //     }
        // }
        std::cout << res << "\n";
	}

    input_file.close();
    

    return 0;
}