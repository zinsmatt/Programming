class Solution {
public:
    int numTrees(int n) {
        vector<int> nums(n+5, 0);
        nums[0] = 1;
        nums[1] = 1;
        nums[2] = 2;
        nums[3] = 5;
        if (n > 3)
        {
            for (int m = 3; m <= n; ++m)
            {
                int count = 0;
                for (int i = 0; i < m; ++i)
                {
                    count += nums[i]*nums[m-1-i];               
                }
                nums[m] = count;
            }
        }
        return nums[n];
    }
};
