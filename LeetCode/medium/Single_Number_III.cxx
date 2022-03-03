class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int r = 0;
        for (auto x : nums)
            r ^= x;
        
        // a^a = 0
        // a^0 = a
        // A bit of r at 1 means that the 2 unique numbers are different at this bit
        // Thus:
        //  - find this position (it is sure it exists are they are not equal)
        //  - then split number based on the value of this bit, using xor to remove pairs
        
        int shift = 1;
        while (r % 2 == 0){
            shift <<= 1;
            r >>= 1;
        }
        
        int a = 0, b = 0;
        for (auto x : nums) {
            if (x & shift) {
                a ^= x;
            } else {
                b ^= x;
            }
        }
        
        return {a, b};
        
    }
};
