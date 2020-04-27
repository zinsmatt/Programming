class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0)
            return 0;
        vector<vector<int>> m(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        int res = 0;
        for (int i = 1; i < m.size(); ++i)
        {
            for (int j = 1; j <m[0].size(); ++j)
            {
                if (matrix[i-1][j-1] == '0')
                    continue;
                m[i][j] = min(m[i-1][j-1], min(m[i-1][j], m[i][j-1])) + 1;
                res = max(res, m[i][j]);
            }
        }
        return res*res;
    }
};
