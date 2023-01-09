class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() == 1)
            return ;
        sort(nums.begin(), nums.end());
        vector<int> out(nums.size());

        int a = 0;
        for (int i = nums.size()-1; i >= ceil(static_cast<double>(nums.size())/2); --i) {
            out[a++] = nums[i-nums.size()/2];
            out[a++] = nums[i];
        }
        if (nums.size()%2 == 1) {
            out[a] = nums[0];
        }
        nums = out;        
    }
};
