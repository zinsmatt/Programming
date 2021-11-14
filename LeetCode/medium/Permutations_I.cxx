class Solution {
    vector<vector<int>> res;
    void solve(vector<int>& arr, vector<bool> used, vector<int> cur)
    {
        if (cur.size() == arr.size())
            res.push_back(cur);
        else
        {
            for (int j = 0; j < arr.size(); ++j)
            {
                if (!used[j])
                {
                    auto u = used;
                    u[j] = true;
                    auto c = cur;
                    c.push_back(arr[j]);
                    solve(arr, u, c);
                }
                
            }
        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        solve(nums, used, {});
        return res;
    }
};
