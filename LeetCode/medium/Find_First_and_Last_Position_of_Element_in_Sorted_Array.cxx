class Solution {
    
    int bin_search_first(const vector<int>& nums, int l, int r, int target)
    {
        if (l > r) return -1;
        if (l == r)
        {
            if (nums[l] == target)
                return l;
            else
                return -1;
        }
        else
        {
            int m = (l+r) /2;
            if (nums[m] >= target) return bin_search_first(nums, l, m, target);
            else return bin_search_first(nums, m+1, r, target);
        }
    }
    
    int bin_search_last(const vector<int>& nums, int l, int r, int target)
    {
         //std::cout << l << " " << r << "\n";
        if (l > r) return -1;
        if (l == r)
        {
            if (nums[l] == target)
                return l;
            else
                return -1;
        }        if (l+1 == r)
        {
            if (nums[r] == target) return r;
            else if (nums[l] == target) return l;
            else return -1;
        }
        else
        {
            int m = (l+r) /2;
            if (nums[m] > target) return bin_search_last(nums, l, m-1, target);
            else return bin_search_last(nums, m, r, target);
        }
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int first = bin_search_first(nums, 0, nums.size()-1, target);
        int last = bin_search_last(nums, 0, nums.size()-1, target);
        return {first, last};
        
    }
};
