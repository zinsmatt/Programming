class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
	std::unordered_map<std::string, vector<int>> unique_res;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); ++i) {
		int target = -nums[i];
		int l = i+1;
        int r = nums.size()-1;
        if (i > 0 && nums[i] == nums[i-1])
            continue;
        while (l < r) {
            if (l == i) ++l;
            if (r == i) --r;
            if (l >= r)
                break;

            int s = nums[l] + nums[r];
            if (s == target) {
                // add
                std::string h;
                if (i < l)
                    h = to_string(nums[i]) + to_string(nums[l]) + to_string(nums[r]);
                else if (i < r)
                    h = to_string(nums[l]) + to_string(nums[i]) + to_string(nums[r]);
                else
                    h = to_string(nums[l]) + to_string(nums[r]) + to_string(nums[i]);
                unique_res[h] = {nums[i], nums[l], nums[r]};
                ++l;
                --r;
            } else if (s < target) {
                ++l;
            } else {
                --r;
            }
        }
    }
    vector<vector<int>> res;
    for (auto it : unique_res)
    	res.push_back(it.second);
    return res;
}
};

