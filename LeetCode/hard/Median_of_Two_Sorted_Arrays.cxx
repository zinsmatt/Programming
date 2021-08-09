class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        int a = 0, b = 0;
        int x;
        for (int i = 0; i < n/2; ++i)
        {
            if (a >= nums1.size())
                x = nums2[b++];
            else if (b >= nums2.size())
                x = nums1[a++];
            else
            {
                if (nums1[a] < nums2[b])
                    x = nums1[a++];
                else
                    x = nums2[b++];
            }
        }
        double m = 0;
        int init = x;

        
        if (a >= nums1.size())
            x = nums2[b++];
        else if (b >= nums2.size())
            x = nums1[a++];
        else
        {
            if (nums1[a] < nums2[b])
                x = nums1[a++];
            else
                x = nums2[b++];
        }
        m += x;
        
        
        if (n % 2 == 0)
        {
            m += init;
            m /= 2;
        }
        return m;
    }
};
