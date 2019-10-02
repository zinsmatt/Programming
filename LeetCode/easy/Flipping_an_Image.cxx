class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> res = A;
        for (auto& row : res)
        {
            std::reverse(row.begin(), row.end());
            std::transform(row.begin(), row.end(), row.begin(), std::logical_not<int>());
        }
        return res;
    }
};
