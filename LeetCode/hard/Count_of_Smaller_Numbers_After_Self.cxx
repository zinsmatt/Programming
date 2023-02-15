class Solution {
    vector<int> res;
public:
    void merge(vector<int>& nums, int l, int m, int r, vector<int>& inds) {
        int l_init = l;
        int m_init = m;
        vector<int> temp(r-l+1);
        vector<int> temp_inds(r-l+1);
        int nb_from_right = 0;
        for (int i = 0; i < temp.size(); ++i) {
            if (m > r || (l < m_init && nums[l] <= nums[m])) {
                temp[i] = nums[l];
                temp_inds[i] = inds[l];
                res[inds[l]] += nb_from_right;
                ++l;
            } else {
                temp[i] = nums[m];
                temp_inds[i] = inds[m];
                nb_from_right++;
                ++m;
            }
        }
        copy(temp.begin(), temp.end(), nums.begin() + l_init);
        copy(temp_inds.begin(), temp_inds.end(), inds.begin() + l_init);
    }

    void mergeSort(vector<int>& nums, int l, int r, vector<int>& inds) {
        if (l < r) {
            int m = (l+r)/2;
            mergeSort(nums, l, m, inds);
            mergeSort(nums, m+1, r, inds);

            merge(nums, l, m+1, r, inds);
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        res.resize(nums.size(), 0);
        
        vector<int> inds(nums.size());
        iota(inds.begin(), inds.end(), 0);

        mergeSort(nums, 0, nums.size()-1, inds);

        return res;
    }
};
