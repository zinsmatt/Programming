class Solution {
    
    int solve(vector<int>& x, int l, int r)
    {
        if (l == r) return x[l];
        
        int m = (r + l) / 2;
        if (x[m] != x[m-1] && x[m] != x[m+1])
            return x[m];
        else if (x[m] == x[m-1]) {
            if ((m-1-l) % 2 == 1) 
                return solve(x, l, m-2);
            else
                return solve(x, m+1, r);
        }
        else {
            if ((r-(m+1)) % 2 == 1)
                return solve(x, m+2, r);    
            else
                return solve(x, l, m-1);    
        }
            
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        return solve(nums, 0,  nums.size()-1);
        
    }
};
