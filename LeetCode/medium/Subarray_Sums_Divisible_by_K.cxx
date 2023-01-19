
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefix = 0;
        vector<int> count(k, 0);
        count[0] = 1;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefix = (prefix + nums[i] % k + k) % k;
            res += count[prefix];
            count[prefix]++;
        }


        return res;
    }
};
