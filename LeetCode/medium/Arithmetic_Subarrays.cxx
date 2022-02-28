class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        std::vector<bool> results;
        for (int i = 0; i < l.size(); ++i) {
            int a = l[i];
            int b = r[i];
            std::vector<int> v(nums.begin()+a, nums.begin()+b+1);
            
            bool res = true;
            sort(v.begin(), v.end());
            int r = v[1] - v[0];
            for (int j = 0; j < v.size()-1; ++j)
            {
                if (v[j+1]-v[j] != r) {
                    res = false;
                    break;
                }
            }
            results.push_back(res);
        }
        return results;        
    }
};
