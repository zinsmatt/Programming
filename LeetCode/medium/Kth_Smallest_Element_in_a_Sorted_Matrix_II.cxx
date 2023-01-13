class Solution {
public:
    int count_less_or_equal(vector<vector<int>>& matrix, int x) {
        int n = matrix.size();
        int r = 0;
        int c = n-1;
        int res = 0;
        while (r < n) {
            while (c >= 0 && matrix[r][c]>x)
                --c;
            if (c < 0)
                break;
            res += c+1;
            ++r;
        }
        return res;        
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix[0][0];
        int n = matrix.size();
        int r = matrix[n-1][n-1];
        int res = 0;
        while (l <= r) {
            int m = (l+r) >> 1;
            // std::cout << "m = " << m << "\n";
            int c = count_less_or_equal(matrix, m);
            // std::cout << "count less " << c << "\n";
            if (c < k) {
                l = m+1;
            } else {
                res = m;
                r = m-1;
            }
        }
        return res;
    }
};
