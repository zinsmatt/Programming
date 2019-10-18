class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> res(nums);
        quickSort(res, 0, res.size()-1);
        return res;        
    }
    
    void quickSort(vector<int>& a, int l, int r)
    {
        if (r-l == 1)
        {
            if (a[r] < a[l])
                swap(a[r], a[l]);
        }
        else if (l < r)
        {
            int r_init = r;
            int l_init = l;
            int p = l;
            ++l;
            while (l < r)
            {
                while (a[l] <= a[p] && l < r) ++l;
                while (a[r] > a[p] && r > l) --r;
                if (l < r)
                {
                    swap(a[r--], a[l++]);
                }
            }
            if (a[p] > a[r])
            {
                swap(a[p], a[r]);
            }
            quickSort(a, p, r-1);
            quickSort(a, l, r_init);
        }
    }
};