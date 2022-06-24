class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> out(nums.size(), 0);
        int a = 0, b = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                out[a] = nums[i];
                a += 2;
            } else {
                out[b] = nums[i];
                b += 2;
            }
        }
        return out;
    }
};
