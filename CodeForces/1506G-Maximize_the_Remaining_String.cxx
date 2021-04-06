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





int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	ll tt=1;
	cin >> tt;
	F(t, tt)
	{
        int n;
        std::string s;
        cin >> s;
        vector<int> count(26, 0);
        n = s.size();
        F (i, n){
            count[s[i]-'a']++;
        }


        vector<bool> done(26, false);
        int i = 0, prev = 0;
        vector<int> local_count(26, 0);
        while (i < n)
        {
//            std::cout << "i  " << i << std::endl;
            if (!done[s[i]-'a'])
            {
                local_count[s[i]-'a']++;
                if (local_count[s[i]-'a'] == count[s[i]-'a'])
                {
                    int j = i;
                    char max = s[i];
                    int max_j = i;
                    // std::cout << "stop at " << max << " " << i << std::endl;
                    // std::cout << "start search until prev=" << prev << std::endl;
                    while (j >= prev)
                    {
                        // std::cout << "check " << j << " " << s[j] << " | ";
                        if ((int)max <= (int)s[j] && !done[s[j]-'a'])
                        {
                            max_j = j;
                            max = s[j];
                        }
                        --j;
                    }
                    //if (j >= 0)                    std::cout << " ((((" << done[j] << "(" << j << ")" << "))))   ";

                    // std::cout << " ==> max at " << max_j << " = " << max << std::endl;
                    std::cout << max;
                    // std::cout << "########### VALIDATE " << max << "\n";
                    done[max-'a'] = true;
                    prev = max_j+1;
                    for (int k = prev; k <= i; ++k)
                        local_count[s[k]-'a']--;

                    //std::cout << "max_j = " << max_j << std::endl;
                    i = prev;
                } else 
                {
                    ++i;
                }
            } else
            {
                ++i;
            }
        }

        std::cout << "\n";

        
    }

    return 0;
}