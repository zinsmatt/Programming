class Solution {
    vector<vector<int>> res;
    void solve(vector<int>& nums, int i, vector<int> cur)
    {
        if (i >= nums.size())
            res.emplace_back(std::move(cur));
        else {
            auto cur2 = cur;
            cur2.push_back(nums[i]);
            solve(nums, i+1, cur2);
            solve(nums, i+1, cur);
        }
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums, 0, {});
        return res;
    }
};

