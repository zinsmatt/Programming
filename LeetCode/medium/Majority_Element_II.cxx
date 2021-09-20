class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a = 0, b = 0;
        int i = 0, j = 0;
        for (auto x : nums)
        {
            if (x == a)
            {
                ++i;
            }
            else if (x == b)
            {
                ++j;
            }
            else if (i == 0)
            {
                a = x;
                ++i;
            }
            else if (j == 0)
            {
                b = x;
                ++j;
            }
            else
            {
                --i;
                --j;
            }
        }
        
        int ca = 0, cb = 0;
        for (auto x : nums)
        {
            ca += (x == a);
            cb += (x == b);
        }
        vector<int> res;
        if (ca > nums.size() / 3) 
            res.push_back(a);
        if (a != b && cb > nums.size() / 3) 
            res.push_back(b);
        return res;
    }
};
