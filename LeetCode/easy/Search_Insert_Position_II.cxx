class Solution {
    int search(vector<int>& v, int t, int l, int r) {
        if (l == r) {
            if (v[l] < t)
                return l+1;
            else
                return l;
        }

        if (l > r) {
            return l;
        }
        
        int m = (l+r) / 2;
        if (v[m] == t)
            return m;
        else if (v[m] < t) {
            return search(v, t, m+1, r);
        } else {
            return search(v, t, l, m);
        }
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size()-1);
    }
};
