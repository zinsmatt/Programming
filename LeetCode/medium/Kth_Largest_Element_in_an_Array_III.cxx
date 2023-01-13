class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size()-1;
        int shift = 0;
        --k;
        while (l <= r) {
            int p = nums[l];
            vector<int> temp(r-l+1);
            int a = 0;
            for (int i = l+1; i <= r; ++i)
            {
                if (nums[i] >= p)
                    temp[a++] = nums[i];
            }
            int ppos = a;
            temp[a++] = p;
            for (int i = l+1; i <= r; ++i)
            {
                if (nums[i] < p)
                    temp[a++] = nums[i];
            }
            for (int k = 0; k < temp.size(); ++k)
                nums[l+k] = temp[k];

            int apos = ppos + shift;
            if (apos == k)
                return p;
            else if (apos > k)
                r = apos - 1;
            else {
                l = apos + 1;
                shift = apos + 1;
            }
        }
        return 0;
    }
};
