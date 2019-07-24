class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a = 0;
        int b = 0;
        int c = 0;
        vector<int> res(nums1.size(), 0);
        
        while (a < m || b < n)
        {
            if (b >= n || a < m && nums1[a] <= nums2[b])
            {
                res[c++] = nums1[a++];
            }
            else
            {
                res[c++] = nums2[b++];
            }
        }
        nums1 = res;
    }
};