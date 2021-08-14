class Solution {
    vector<vector<int>> combis;
    void solve(int k, int n, int cur, int last, vector<int> cur_combi) //vector<int> done)
    {
        if (cur > n) return;
        if (n == cur)
        {
            if (k == cur_combi.size())
            {
                combis.push_back(cur_combi);
            }
            return;
        }
        
        {
            for (int i = last+1; i <= 9; ++i)
            {
                auto cpy = cur_combi;
                cpy.push_back(i);
                solve(k, n, cur+i, i, cpy);
            }
        }
    }
        
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        solve(k, n, 0, 0, {});
        return combis;
    }
};
