// This is just a template solution used as initial script


#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>     /* abs */

 
#define F(i, n) for (ll i = 0; i < n; ++i)

#define VPRINT(name, v) \
    cerr << name << " : "; \
    for (auto& e : v) { \
        cerr << e << " "; \
    } \
    cerr << std::endl;

#define LPRINT(name, l) \
    cerr << "list " << name << " : "; \
    for (auto it = l.begin(); it != l.end(); ++it) { \
        cerr << *it << " "; \
    } \
    cerr << std::endl;

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


ofstream dbg("dbg.txt", std::ofstream::out);




int query(int i)
{
	cout << i;
	cout << std::endl << std::flush;

	dbg << i;
	dbg << std::endl << std::flush;
	char c;
	cin >> c;
	if (c == 'N')
	    return -1;
	else if (c == '0')
	    return 0;
    else
	   return 1;
}


int answer(vector<int>& r)
{
	for (auto b : r)
		cout << b;
	cout << std::endl << std::flush;


	for (auto b : r)
		dbg << b;
	dbg << std::endl << std::flush;

	char a;
	cin >> a;
	if (a == 'Y')
		return 1;
	else
		return 0;
}

bool fill_v(vector<int>& v, int shift=0)
{
    F(i, 10)
	{
		v[i] = query(i + 1 + shift);
	}
	return true;
}

/*int find_case(vector<int>& a, vector<int>& c)
{
	{

		if (vector<int>(a.begin()+1, a.end()) == vector<int>(c.begin(), c.begin()+9))
			return 4;

        bool case1 = true;
        F(i, 9)
        {
            if (a[i+1] != (c[i]+1)%2)
            {
                case1 = false;    
                break;
            }
        }
        if (case1)
        	return 1;

		bool case2 = a.back() == c.back();
		if (case2)
			return 2;
		else
			return 3;
	}
}*/

vector<int> poss_cases(const vector<int>& p, const vector<int>& c)
{
	//p : prev ae
	//c: cur ae

	if (p[0] == 0 && p[1] == 0)
	{
		if (c[0] == 0)
			return {2, 4};
		else
			return {1, 3};
	}
	else if (p[0] == 0 && p[1] == 1)
	{
		if (c[0] == 0)
			return {3, 4};
		else
			return {1, 2};
	}
	else if (p[0] == 1 && p[1] == 0)
	{
		if (c[0] == 0)
			return {1, 2};
		else
			return {3, 4};
	}
	else
	{
		if (c[0] == 0)
			return {1, 3};
		else
			return {2, 4};
	}
}

int find_case(const vector<int>& prev, const vector<int>& cur)
{

	auto poss1 = poss_cases({prev[0], prev[3]}, {cur[0], cur[3]});
	auto poss2 = poss_cases({prev[1], prev[2]}, {cur[1], cur[2]});

	int occ[4] = {0, 0, 0, 0};
	for (auto x : poss1) occ[x-1]++;
	for (auto x : poss2) occ[x-1]++;

	auto best_case = arg_max(vector<int>(occ, occ+4)) + 1;
	return best_case;
}

void transform_inplace(vector<int>& v, int cas)
{
	if (cas == 1)
	{
		for (auto& x : v){
			if (x != -1)
				x = !x;
		}
	} else if (cas == 2)
	{
		reverse(v.begin(), v.end());
	}
	else if (cas == 3)
	{
		for (auto& x : v) {
			if (x != -1)
				x = !x;
		}
		reverse(v.begin(), v.end());	
	}
}

bool find_configs(const vector<int>& v, int start, vector<int>& configs)
{
	vector<int> cfgs(5, 0);
	F(i, 5)
	{
		if (v[start+i] == v[v.size()-1-start-i])
			cfgs[i] = 1; //sym
		else
			cfgs[i] = 2; //asym
	}
	int cfg1 = 0;
	int cfg2 = 1;
	while (cfg2 < 5 && cfgs[cfg2] == cfgs[cfg1])
		++cfg2;
	//cerr << "cfg 1 2 = " << cfg1 << " " << cfg2 << "\n";
	if (cfg2 == 5)
	{
		return false;
	}
	else
	{
		configs.resize(2);
		configs[0] = cfg1 + start;
		configs[1] = cfg2 + start;
		return true;
	}
}

int main()
{
	ll tt, b;
	cin >> tt >> b;

	F(tti, tt)
	{
	    if (b == 10)
	    {
    		vector<int> res(b, 0);
    		F(i, 10)
    		{
    		    auto rep = query(i+1);
    		    if (rep == -1)
    		        return -1;
    			res[i] = rep;
    		}
    
    		auto a = answer(res);
    		if (!a)
    		{
    			return -1;
    		}
	    }
	    else if (b == 20)
	    {

	    	vector<int> res(20, -1);
	    	F(i, 5) res[i] = query(i+1);
	    	F(i, 5) res[i+15] = query(i+1+15);

	    	//VPRINT("res init = ", res)


	    	// do find config 
	    	vector<int> cfgs(2);
	    	bool res_config1 = find_configs(res, 0, cfgs);

	    	if (!res_config1)
	    	{
	    		F(i, 5) res[i+5] = query(i+1+5);
	    		F(i, 5) res[i+10] = query(i+1+10);
	    		//VPRINT("res 2nd config  = ", res)
	    		bool res_config2 = find_configs(res, 5, cfgs);
	    		if (!res_config2)
	    		{
	    	  		F(i, 5) res[i+3] = query(i+1+3);
	    			F(i, 5) res[i+12] = query(i+1+12);
	    			//VPRINT("res 3rd config  = ", res)
		    		bool res_config3 = find_configs(res, 3, cfgs);

		    		if (!res_config3)
		    		{
		    			bool sym = res[9] == res[10];
		    			F(i, 10) res[i] = query(i+1);
		    			if (sym)
		    			{
		    				F(i, 10) res[b-1-i] = res[i];
		    			}
		    			else
		    			{
		    				F(i, 10) res[b-1-i] = !res[i];
		    			}

		    			auto ans = answer(res);
		    			if (!ans)
		    			{
		    				//cerr << "ERROR\n" << fflush;
		    				return -1;
		    			}
		    			continue; //next test case
		    		}
	    		}
	    	}

	    	// WARNING DO IT NI 3 !!!!!

	    	
	    	auto cfg1 = cfgs[0];
	    	auto cfg2 = cfgs[1];
	    	//cerr << "config found: " << cfg1 << " " << cfg2 << "\n";

	    	vector<bool> done(20, false);
	    	done[cfg1] = true;
	    	done[cfg2] = true;

	    	int next_todo = 0;
	    	while (1)
	    	{

	    		// at this moment at least the queries are known
	    		vector<int> prev = {res[cfg1], res[cfg2], res[b-1-cfg2], res[b-1-cfg1]};

	    		vector<int> cur(4);
	    		cur[0] = query(cfg1+1);
	    		cur[1] = query(cfg2+1);
	    		cur[2] = query(b-cfg2);
	    		cur[3] = query(b-cfg1);

	    		//VPRINT("prev : ", prev)
	    		//VPRINT("cur : ", cur)


	    		auto cas = find_case(prev, cur);

	    		//cerr << "Found best case " << cas << "\n";


	    		//VPRINT("res before : ", res)
	    		transform_inplace(res, cas);
				//VPRINT("res after : ", res)

	    		// normally the elements used for configs are correctly transformed

	    		for (int k = 0; k < 3 && next_todo < 10; ++k)
	    		{
	    			while (next_todo < 10 && done[next_todo])
	    				++next_todo;
	    			if (next_todo < 10)
	    			{
		    			//cerr << "query " << next_todo << "\n";
		    			res[next_todo] = query(next_todo+1);
		    			res[b-1-next_todo] = query(b-next_todo);
		    			done[next_todo] = true;
		    			done[b-1-next_todo] = true;
		    			//VPRINT("upt ", res)
	    			}
	    		}

	    		//VPRINT("final ", res)

	    		if (next_todo >= 10)
	    			break;

	    	}

	    	auto ans = answer(res);
	    	if (!ans)
	    	{
	    		return -1;
	    	}        
	    	//cerr << "=======> RESULT \n";
	    	//VPRINT("answer: ", res)
	    	//std::cerr << "verification : " << ans << "\n";

	    }
	}
	


	
    return 0;
}
