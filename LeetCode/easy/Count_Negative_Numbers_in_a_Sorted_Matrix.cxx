class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i = 0; 
        int j = n-1;
        int res = 0;
        while (j >= 0 && i < m) {
            while (i < m && grid[i][j] >= 0) {
                ++i;
            }
            if (i < m) {
                res += m-i;
                --j;
            }
        }
        return res;
    }
};
