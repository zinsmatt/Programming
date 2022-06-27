class Solution {
    int binary_search(vector<int>& arr, int l, int r, int t) {

        if (l >= r)
            return arr[l] == t ? l : -1;
        
        int m = ( l + r) / 2;
        if (arr[m] == t) {
            return m;
        } else if (t < arr[m]) {
            return binary_search(arr, l, m-1, t);
        } else {
            return binary_search(arr, m+1, r, t);
        }
    }
public:
    int search(vector<int>& nums, int target) {
        return binary_search(nums, 0, nums.size()-1, target);        
    }
};
