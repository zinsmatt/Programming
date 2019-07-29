class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n, vector<int>(n));
        int a = 0, b = n-1, c = 0, d = n-1;
        int i = 1;
        int row = 0, col = 0;
        while (i <= n*n)
        {
            for (int j = a; j <= b; ++j)
            {
                m[row][j] = i++;
                col++;
                std::cout << row << " " << j << std::endl;
            }
            ++c;
            --col;
            ++row;
            for (int j = row; j <= d; ++j)
            {
                m[j][col] = i++;
                row++;
                                std::cout << j << " " << col << std::endl;

            }
            --row;
            --b;
            --col;
            for (int j = col; j >= a; --j)
            {
                m[row][j] = i++;
                col--;
                                std::cout << row << " " << j << std::endl;

            }
            ++col;
            --d;
            --row;
            for (int j = row; j >= c; --j)
            {
                m[j][col] = i++;
                row--;
                                std::cout << j << " " << col << std::endl;

            }
            ++row;
            ++a;
            ++col;
        }
        return m;
    }
};