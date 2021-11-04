class Solution {
    
public:
    int bin_search(const vector<int>& a, int l, int r, int t)
    {
        if (l>r)
        {
            return -1;
        }
        int m = (l+r) / 2;
        if (t == a[m])
            return m;
        else
        {
            if (a[m] < t)
            {
                return bin_search(a, m+1, r, t);
            }
            else
            {
                return bin_search(a, 0, m-1, t);
            }
        }
    }
    
    
    int search(vector<int>& nums, int target) {
        return bin_search(nums, 0, nums.size()-1, target);        
    }
};
