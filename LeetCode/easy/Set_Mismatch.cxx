class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> count(10001, 0);
        for (auto k : nums)
            ++count[k];
        int a, b;
        for (int i = 1; i <= nums.size(); ++i)
        {
            if (count[i] > 1)
                a = i;
            if (count[i] == 0)
                b = i;
        }
        return {a, b};
    }
};