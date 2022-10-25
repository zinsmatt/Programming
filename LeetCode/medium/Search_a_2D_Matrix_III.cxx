class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        int l = 0, r = matrix.size();
        while (l < r) {
            
            int m = (l + r) / 2;
            if (matrix[m][0] == target) {
                return true;
            }
            
            if (matrix[m][0] <= target) {
                l = m+1;
            } else {
                r = m;
            }
        }

        int row = 0;
        if (l >= matrix.size()) {
            row = matrix.size() - 1;
        }
        else if (target < matrix[l][0]) {
            if (l > 0)
                row = l-1;
            else
                return false;
        }
        
        
        l = 0;
        r = matrix[0].size();
        
        
        while (l < r) {
            int m = (l + r) / 2;
            if (matrix[row][m] == target)
                return true;
            if (matrix[row][m] < target)
                l = m + 1;
            else
                r = m- 1;
        }
        
        if (l < matrix[0].size())
            return matrix[row][l] == target;
        return false;
        
    }
};
