class Solution {
public:
    
    // O(n) version
    int numberOfArithmeticSlices(vector<int>& nums) {

        if (nums.size() < 3)
            return 0;
        int res = 0;
        
        int i = 0;
        while (i < nums.size()-2)
        {
            int j = i+1;
            int d = nums[i+1]-nums[i];
            while (j < nums.size() && nums[j] - nums[j-1] == d)
            {
                ++j;
            }
            int n = j-i;
            
            auto p = (n-2)*(n+1)-(n*(n+1))/2+3;
            res += p;
            i = j-1;
        }
        return res;
    }
    
    
    
    
    
    
    
    
    
    
// Less optimized version (O(n^2))    
//         int numberOfArithmeticSlices(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         if (nums.size() < 3)
//             return 0;
//         int res = 0;
        
//         int i = 0;
//         while (i < nums.size()-2)
//         {
//             int j = i+1;
//             int d = nums[i+1]-nums[i];
//             while (j < nums.size() && nums[j] - nums[j-1] == d)
//             {
//                 if (j-i >= 2)
//                     res++;
//                 ++j;
//             }
//             ++i;
//         }
//         return res;
//     }
};

