class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return {};
        vector<int> res;
        for (int jj = 0; jj < matrix[0].size() + matrix.size(); ++jj)
        {
            int i = 0;
            int j = jj;
            
            vector<pair<int, int>> indices;
            while (j >= 0 && i < matrix.size())
            {
                if (j < matrix[0].size())
                {
                    indices.emplace_back(i, j);
                }
                ++i;
                --j;                
            }
            
            if (jj % 2 == 0)
                std::reverse(indices.begin(), indices.end());
            
            for (auto& p : indices)
                res.push_back(matrix[p.first][p.second]);
        }
        return res;
    }
    
    pair<int, int> t(int i, int j)
    {
        return std::make_pair(j, i);
    }
};