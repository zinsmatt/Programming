class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        for (int i = 0; i < std::pow(2, nums.size()); ++i) {
            vector<int> set;
            int x = i;
            int k = 0;
            while (x) {
                if (x % 2)
                    set.push_back(nums[k]);
                ++k;
                x /= 2;
            }
            res.emplace_back(std::move(set));
        }
        return res;
        
    }
};

