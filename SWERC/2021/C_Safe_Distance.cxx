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

double is_possible(double d, const std::vector<std::vector<double>>& points, int X, int Y)
{
    std::vector<int> sets(points.size(), -1);
    F (i, points.size()) {
        for (int j = i+1; j < points.size(); ++j) {
            double dist = distance(points[i], points[j]);
            if (dist < d) {
                union_(sets, i, j);
            }
        }
    }
    // VPRINT("sets", sets);
    std::set<int> NW, SE;
    F (i, points.size()) {
        if (points[i][0] < d/2 || Y-points[i][1] < d/2) {
            NW.insert(find(sets, i));
        }
        if (X - points[i][0] < d/2 || points[i][1] < d/2) {
            SE.insert(find(sets, i));
        }
    }
    // std::cout << "NW: ";
    // for (auto e: NW) std::cout << e <<  " ";
    // std::cout << std::endl;
    // std::cout << "SE: ";
    // for (auto e: SE) std::cout << e <<  " ";
    // std::cout << std::endl;
    

    bool blocked = false;
    F (i, sets.size()) {
        if (sets[i] == -1) {
            if (SE.find(i) != SE.end() && NW.find(i) != NW.end()) {
                blocked = true;
                break;
            }
        }
    }
    return !blocked;
}


double solve(double left, double right, const std::vector<std::vector<double>>& points, int X, int Y) {
    double m = (left + right) / 2;
    //std::cout << "try " << left << " " << right << "  => mid " << m  << "   ";
    if (right-left < 1e-6) return m;

    auto ret = is_possible(m, points, X, Y);
    //std::cout << " ==> " << ret << std::endl;
    if (ret) {
        return solve(m, right, points, X, Y);
    } else {
        return solve(left, m, points, X, Y);
    }
}

int main()
{
	ll tt=1;
	// cin >> tt;
	F(t, tt)
	{
        ll X, Y;
        cin >> X >> Y;
        int n;
        cin >> n;
        std::vector<std::vector<double>> points(n, vector<double>(2, 0.0));
        F (i, n) {
            cin >> points[i][0] >> points[i][1];
        }

        auto res = solve(0.0, std::min(X, Y), points, X, Y);
        res /= 2;
        std::cout << std::fixed << std::setprecision(6) << res << "\n";

	}
    

    return 0;
}