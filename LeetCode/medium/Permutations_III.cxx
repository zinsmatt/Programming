class Solution {

vector<vector<int>> perms;
void generate(vector<int>& nums, vector<bool> done, vector<int> cur)
{
	if (cur.size() == nums.size()) {
		perms.emplace_back(std::move(cur));
	} else {
		for (int i = 0; i < nums.size(); ++i) {
			if (!done[i]) {
				auto done2 = done;
                done2[i] = true;
                auto cur2 = cur;
                cur2.push_back(nums[i]);
                generate(nums, done2, cur2);
            }
		}
	}
}

public:
    vector<vector<int>> permute(vector<int>& nums) {
    	vector<bool> done(nums.size(), false);
        generate(nums, done, {});
        return perms;
    }
};

