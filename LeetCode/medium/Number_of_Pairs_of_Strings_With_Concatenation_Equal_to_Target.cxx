class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i].size() < target.size() && target.substr(0, nums[i].size()) == nums[i])
            {
                for (int j = 0; j < nums.size(); ++j) {
                    if (i != j && nums[j].size() + nums[i].size() == target.size()) {
                        if (nums[j] == target.substr(nums[i].size())) {
                            res++;
                        }
                    }
                }
            }
        }
        return res;
    }
};
