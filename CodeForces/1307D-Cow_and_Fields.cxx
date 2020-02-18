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


int dfs(const vector<vector<int>>& g, vector<int>& dist, int start, int end=-1)
{
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


int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> spe(k);
    vector<bool> s(n+1, false);
    F(i, k){
        cin >> spe[i];
        s[spe[i]] = true;
    }
    int ok = 0;
    vector<vector<int>> g(n+1, vector<int>());
    F(i, m)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        if (s[a] && s[b])
        {
            ok = 1;
        }
    }

    if (k == 2)
    {
        int a = spe[0], b = spe[1];
        g[a].push_back(b);
        g[b].push_back(a);
        ok = 2;
    }


    vector<int> dist(n+1, INF);
    dfs(g, dist, n);

    //for (int i = 0; i < dist.size(); ++i)
    //  cout << dist[i] <<  " ";
    //cout << std::endl;

    if (ok == 1 || ok == 2)
    {
        cout << dist[1] << std::endl;
    }
    else
    {
        //cout << "speical case" << std::endl;
        vector<int> spe_dist_to_n(k, INF);
        for (int i =0; i <k; ++i)
        {
            spe_dist_to_n[i] = dist[spe[i]];
        }
        //VPRINT("spe_dist_to_n", spe_dist_to_n)

        vector<int> spe_dist_to_zero(k, INF);
        vector<int> dist_from_1(n+1, INF);
        dfs(g, dist_from_1, 1);
        for (int i = 0; i < k; ++i)
        {
            spe_dist_to_zero[i] = dist_from_1[spe[i]];
        }

        //VPRINT("spe_dist_to_zero", spe_dist_to_zero)

        //if (s[1])
        //{
		//	vector<int> idx(k, 0);
        //	iota(idx.begin(), idx.end(), 0);
        //	sort(idx.begin(), idx.end(), [&spe_dist_to_n] (int i, int j) {
	    //        return spe_dist_to_n[i] > spe_dist_to_n[j];
        //	});
        //	int best_idx = idx[0];
        //	if (spe[idx[0]] == 1)
        //		best_idx = idx[1];
        //	if (spe_dist_to_n[best_idx] + 1 >= dist[1])
        //	{
        //		cout << dist[1] << std::endl;
        //		return 0;
        //	}
        //}

        vector<int> min_dist(k);
        F(i, k) {
            min_dist[i] = spe_dist_to_zero[i] - spe_dist_to_n[i];
            //min_dist[i] = spe_dist_to_zero[i];
        }

        //VPRINT("min_dist", min_dist);
        
        
        vector<int> idx(k, 0);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&min_dist] (int i, int j) {
            return min_dist[i] < min_dist[j];
        });
        /*int start = max(0, min(k-50, (int)(0.75*k)));
        int size = k-start;
        vector<int> v(size);
        int a = 0;
        for (int i = start; i < k; ++i)
            v[a++] = idx[i];
        */
        

        int max_to_zero = -INF;
        int nouv = -INF;
        for (int aai = 0; aai < k; ++aai)
        //for (int aa = 0; aa < k; ++aa)
        {
        	int aa = idx[aai];
        	nouv = max(nouv, max_to_zero + 1 + spe_dist_to_n[aa]);
        	max_to_zero = max(max_to_zero, spe_dist_to_zero[aa]);
        	//int temp = spe_dist_to_zero[idx[aai]] + 1 + max_suffix[aai];
        	//nouv = max(nouv, temp);
        	//if (temp >= dist[1])
        	//{
        	//	nouv = temp;
        	//	break;
        	//}
            
            /*for (int bbi = aai+1; bbi < k; ++bbi)
            //for (int bb = aa+1; bb < k; ++bb)
            {
                int aa = idx[aai];
                int bb = idx[bbi];

                int temp = min(spe_dist_to_zero[aa] + spe_dist_to_n[bb],
                               spe_dist_to_zero[bb] + spe_dist_to_n[aa]) + 1;
                //cout << "add btw " << spe[aa] << " " << spe[bb] << " => new route " << temp << std::endl;
                if (temp > nouv){
                    nouv = temp;
                }
                if (temp >= dist[1]) {
                	nouv = temp;
                	break;
                }
            }
            */
        }

        //nouv = min(spe_dist_to_zero[aa] + spe_dist_to_n[bb],
        //           spe_dist_to_zero[bb] + spe_dist_to_n[aa]) + 1;

        if (nouv < dist[1])
            dist[1] = nouv;
        cout << dist[1] << std::endl;
    }

    return 0;
}