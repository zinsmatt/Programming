class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> res(nums.size());
        k %= nums.size();
        int s = nums.size()-k;
        for (int i = 0; i < nums.size(); ++i)
        {
            res[i] = nums[(s+i)%nums.size()];
        }
        nums = res;        
    }
};
