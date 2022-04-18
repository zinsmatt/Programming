class Solution {
    int invert(int x, int m) {
        int res = 0;
        for (int i = 0; i < m; ++i) {
            auto r = x % 2;
            r = (r+1) % 2;
            
            res += r * std::pow(2, i);
            x /= 2;
        }
        return res;
    }
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {       
        vector<int> xors(nums.size());
        vector<int> res;
        int prev = 0;
        for (int i = 0; i < nums.size(); ++i) {
            xors[i] = prev ^ nums[i];
            prev = xors[i];
        }
        
        for (int i = nums.size()-1; i >= 0; --i) {
            res.push_back(invert(xors[i], maximumBit));
        }
        return res;
    }
};
