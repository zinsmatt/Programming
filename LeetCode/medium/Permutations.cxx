class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(nums, {}, res, unordered_map<int, bool>());
        return res;        
    }
    
    void dfs(const vector<int>& nums, vector<int> cur,
             vector<vector<int>>& res, unordered_map<int, bool> used)
    {
        if (cur.size() == nums.size())
            res.push_back(cur);
        else
        {
            for (auto e : nums)
            {
                if (used.find(e) == used.end())
                {
                    auto used_copy = used;
                    used_copy[e] = true;
                    auto cur_copy = cur;
                    cur_copy.push_back(e);
                    dfs(nums, cur_copy, res, used_copy);
                }
            }
        }
    }
};