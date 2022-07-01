class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
	vector<int> prev(nums.size(), 1);
	vector<int> post(nums.size(), 1);
	prev[0] = nums[0];
	post[nums.size()-1] = nums.back();
	for (int i = 1; i < nums.size(); ++i) {
		prev[i] = prev[i-1] * nums[i];
}
for (int i = nums.size()-2; i >= 0; --i) {
	post[i] = post[i+1] * nums[i];
}

vector<int> res(nums.size());
for (int i = 0; i < nums.size(); ++i) {
	int v = 1;
	if (i > 0) v *= prev[i-1];
	if (i < nums.size()-1) v *= post[i+1];
	res[i] = v;
}
        	return res;
    }
};


