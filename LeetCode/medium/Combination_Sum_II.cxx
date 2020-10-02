class Solution {
public:
    
    void f(vector<int>& c, int target, vector<int>& v, vector<vector<int>>& res, int s)
    {
        if (target < 0)
            return;
        if (target == 0)
        {
            res.push_back(v);
            return ;
        }
        
        int i = s;
        int prev = -1;
        while (i < c.size() && c[i] <= target)
        {
            
            if (prev == c[i]) {
                i++;
                continue;
            }
            prev = c[i];
            v.push_back(c[i]);
            f(c, target - c[i], v, res, i+1);
            v.pop_back();
            i++;
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        int size = distance(candidates.begin(), upper_bound(candidates.begin(), candidates.end(), target));
        candidates.resize(size);
        vector<int> v;
        f(candidates, target, v, res, 0);
        return res;
    }
};
