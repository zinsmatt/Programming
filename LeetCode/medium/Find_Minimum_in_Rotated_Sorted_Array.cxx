class Solution {
    
    int solve(vector<int>& v, int l, int r)
    {
        if (l >= r) return v[l];
        
        if (v[l] < v[r])
        {
            return v[l];
        }
        else
        {
            int m = (r+l) / 2;
            if (v[m] < v[l])
            {
                return solve(v, l, m);
            }
            else
            {
                return solve(v, m+1, r);
            }
        }
    }
public:
    int findMin(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};
