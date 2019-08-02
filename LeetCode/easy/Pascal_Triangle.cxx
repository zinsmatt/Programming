class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0)
            return vector<vector<int>>();
        vector<vector<int>> res;
        res.push_back(vector<int>({1}));
        for (int i = 1; i < numRows; ++i)
        {
            vector<int> line ;
            line.push_back(1);
            for (int j = 1; j < res[i-1].size(); ++j)
            {
                line.push_back(res[i-1][j-1] + res[i-1][j]);
            }
            line.push_back(1);
            res.push_back(line);
        }
        return res;
    }
};