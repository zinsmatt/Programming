class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int s = (nums.size() * (nums.size()+1)) / 2;
        for (auto x : nums)
            s -= x;
        return s;
    }
};
